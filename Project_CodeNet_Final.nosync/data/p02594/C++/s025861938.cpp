#include<iostream>
#include<bits/stdc++.h>

#define FASTIO ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define  ll long long
#define sc second
#define fr first
const int nax = 1e6+5;
const int mod = 1e4+7;
using namespace std;
typedef pair<double,double> pi;
typedef tuple<int,int,int> tu;


signed main()
{
	FASTIO;
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	freopen("error.txt" , "w" , stderr);
    #endif
	int n;
	cin >> n;
	if(n>=30)
		cout << "Yes"<< "\n";
	else
		cout << "No" << "\n";
	return 0;

}

