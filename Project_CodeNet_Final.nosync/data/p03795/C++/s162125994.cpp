#include<iostream>
using namespace std;

int main()
{
	int a,b,N;
	cin >> N;
	b = 200*(N / 15);
	a = 800 * N;
	cout << a - b;
    return 0;
}