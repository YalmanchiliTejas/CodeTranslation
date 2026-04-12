#include <bits/stdc++.h>
using namespace std;
#define fi first
#define endl "\n"
#define se second
#define ll long long
//priority_queue<int, vector<int>, greater<int> > pq;
#define _CRT_SECURE_NO_DEPRECATE
const int N = 105;
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
const ll mod =  1e9+7;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	 int n,m;
	 cin>>n>>m;
	 int c1=0;
	 string s[n];
	 rep(i,0,n)
	 {
	 	cin>>s[i];
	 	for(int j=0;j<s[i].size();j++)
	 	{
	 		if(s[i][j]=='#')
	 		c1++;
		 }
	 }
	 int mn=0;
	 int cnt=0;
	 rep(i,0,n)
	 {
	 	rep(j,0,m)
	 	{
	 		if(s[i][j]=='#')
	 		{
	 			if(mn<=j&&(abs(j-mn)<=1))
	 			{
	 				cnt++;
	 				mn=j;
				 }
			 }
		 }
	 }
	 if(c1==cnt)
	 {
	 	cout<<"Possible";
	 }
	 else
	 cout<<"Impossible";
	 }
	 

