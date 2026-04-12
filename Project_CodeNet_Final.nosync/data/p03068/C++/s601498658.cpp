#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
#define eps LDBL_EPSILON
#define moder 1000000007
#define int long long
#define double long double
#define ll long long
#define INF LLONG_MAX/3
#define P pair<int,int>
#define prique priority_queue<int,vector<int>,greater<int>>
#define ggr getchar();getchar();return 0
using namespace std;
signed main(){
	int n,k;
	string s;
	cin>>n>>s>>k;
	char c=s[k-1];
	for(char a:s){
		if(a!=c)a='*';
		cout<<a;
	}
	cout<<endl;
	ggr;
}