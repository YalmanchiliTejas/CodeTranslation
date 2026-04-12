#include<bits/stdc++.h>
#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<map>
#include<queue>
#include<set>
#include<stack>
#include<string>
#include<sstream>
#include<vector>
#define inf 2147483647
#define rep(i,a,b) for(int i=a;i<b;i++)
#define  rr read()
#define repb(i,a,b) for(int i=a;i<=b;i++)
#define CloseIo   ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define ll long long
#define MAXSIZE 60
using namespace std;
const int N = 1e6 + 5;
const ll mo = 1e10 +7;
const int M = 100+50;
const int mod = 100;
int main(){
	int n;
	string s;
	int k;
	cin>>n>>s>>k;
	for(int i=0;i<s.length();i++)
		if(s[i]==s[k-1])
			cout<<s[i];
		else
			cout<<"*";
	cout<<"\n";
    return 0;
}