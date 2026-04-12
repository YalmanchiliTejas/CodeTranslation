//#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <algorithm>

#include <climits>
#include <cmath>
#include <cstring>

#include <iomanip>

using namespace std;

#define FAST       			ios_base :: sync_with_stdio(false); cin.tie(NULL); 
#define endl "\n"

typedef long long int  ll;
typedef unsigned long long int ull;


int main()
{
	FAST;
	int n,m;
	cin >> n >> m;
	
	if(n == m)
		cout << "Yes";
	else
		cout << "No";
	return 0;
}