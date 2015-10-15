// haps_hashes.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"


int _tmain(int argc, _TCHAR* argv[])
{
	return 0;
}

// heaps_hashes.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "mutable_heap.h"
#include <iostream>
#include <cstdlib>

using namespace std;



int main()
{
	mutable_heap<int> YEA;

	YEA.push(5);
	YEA.push(4);
	YEA.push(3);
	YEA.push(10);
	YEA.push(50);
	YEA.push(20);
	cout << YEA.get_data(1) << endl;
	cout << YEA.get_hash(50) << endl;
	cout << YEA.get_hash(5) << endl;
	cout << YEA.pop() << endl;

	system("pause");
}
