//#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <iomanip>

using namespace std;

#define FAST       			ios_base :: sync_with_stdio(false); cin.tie(NULL); 
#define endl "\n"

typedef long long int  ll;
typedef unsigned long long int ull;


int main()
{
	FAST;
	int a,b,c;
	cin >> a >> b >> c;

	a -= c;
	b = b+c;
	cout << a/b;
	return 0;
}