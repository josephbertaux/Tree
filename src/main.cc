#include "Tree.h"

int main()
{
	Tree<int> t;

	Tree<int>::iterator<DepthFirst> itr1 = t.begin<DepthFirst>();
	Tree<int>::iterator<DepthFirst> itr2 = t.end<DepthFirst>();

	std::cout << (itr1 == itr2) << std::endl;
	std::cout << (itr1 == t.begin<DepthFirst>()) << std::endl;

	Tree<int>::iterator<DepthFirst> itr = t.begin<DepthFirst>();
	++itr;

	return 0;
}
