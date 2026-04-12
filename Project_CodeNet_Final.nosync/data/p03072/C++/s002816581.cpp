#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <cstdlib>
#include <list>
#include <numeric>
#define rep(i,n) for(int i=0;i<n;i++)
#define all(x) (x).begin(),(x).end()
using namespace std;

int a, b, c=0, n, k;
string s,t;
//cout<<<<endl;


int main()
{
	cin >> n ;
	vector<int> h(n);
	rep(i, n)
		cin>> h.at(i);
	c = h[0]; int t = 0;
	rep(i, n)
	{
		if (h[i] >= c)
		{
			t++;
			c = h[i];
		}
	}
	cout << t << endl;	
}
