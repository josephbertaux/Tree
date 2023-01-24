#ifndef TREE_H
#define TREE_H

#include <vector>
#include <iterator>
#include <iostream>

template <typename T>
class Tree
{
protected:
	Tree<T>* root;
	std::vector<Tree<T>> leaves;

public:
	T value;

	Tree() : root(nullptr), value() {leaves.clear();}

	class iterator_base
	{
	public:
		typedef Tree<T>				value_type;
		typedef Tree<T>*			pointer;
		typedef Tree<T>&			reference;
		typedef size_t				size_type;
		typedef ptrdiff_t			difference_type;
		typedef std::bidirectional_iterator_tag	iterator_category;

		iterator_base() : ptr(nullptr) {};
		iterator_base(pointer p) : ptr(p) {};

		reference operator*(){return *ptr;}
		pointer operator->(){return ptr;}

		friend bool operator==(const iterator_base& lhs, const iterator_base& rhs){return lhs.ptr == rhs.ptr;}
		friend bool operator!=(const iterator_base& lhs, const iterator_base& rhs){return lhs.ptr != rhs.ptr;}

	protected:
		pointer ptr;
	};

	template <typename U>
	class iterator : public iterator_base
	{
	public:
		using iterator_base::iterator_base;

		iterator<U>& operator++(){return U::template prefix_increment<T>(this);}
		iterator<U>& operator--(){return U::template prefix_decrement<T>(this);}
	};

	template <typename U>
	iterator<U> begin(){return U::begin(this);}
	template <typename U>
	iterator<U> end(){return U::end(this);}

	friend class DepthFirst;
};

class DepthFirst
{
public:
	template <typename T>
	static typename Tree<T>::template iterator<DepthFirst>& prefix_increment(typename Tree<T>::template iterator<DepthFirst>* itr)
	{
		std::cout << "depth first increment called" << std::endl;
		return *itr;
	}

	template <typename T>
	static typename Tree<T>::template iterator<DepthFirst>& prefix_increment(typename Tree<T>::template iterator<DepthFirst>* itr)
	{
		std::cout << "depth first increment called" << std::endl;
		return *itr;
	}

	template <typename T>
	static typename Tree<T>::template iterator<DepthFirst> begin(Tree<T>* p)
	{
		std::cout << "depth first begin called" << std::endl;
		return p->root ? begin(p->root) : typename Tree<T>::template iterator<DepthFirst>(p);
	}

	template <typename T>
	static typename Tree<T>::template iterator<DepthFirst> end(Tree<T>* p)
	{
		std::cout << "depth first end called" << std::endl;
		return typename Tree<T>::template iterator<DepthFirst>(nullptr);
	}
};

#endif
