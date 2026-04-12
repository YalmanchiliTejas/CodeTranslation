//2ÂÌ®aÆbðÇÝÝA
//a<bÌÆ«Í "a < b"
//a>bÌÆ«Í "a > b"
//a==bÌÆ«Í "a == b"
//ÆoÍ¹æ

#include<iostream>
using namespace std;

int main(void)
{
	int a, b;
	cin >> a >> b;
	if(a > b)
		cout << "a > b" << endl;
	else if(a < b)
		cout << "a < b" << endl;
	else
		cout << "a == b" << endl;
	return 0;
}