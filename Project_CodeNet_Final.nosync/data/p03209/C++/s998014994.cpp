#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
#define eps LDBL_EPSILON
#define moder 1000000007
#define int long long
#define ll long long
#define INF LLONG_MAX/3
#define P std::pair<int,int>
#define prique priority_queue<int,vector<int>,greater<int>>
using namespace std;
int n,x,a[60],b[60];
int sumpaty(int l,int m){
	if(m==0)return 0;
	if(l==0)return 1;
	if(m==1)return 0;
	if(1+a[l-1]>=m){
		return sumpaty(l-1,m-1);
	}
	return b[l-1]+1+sumpaty(l-1,min(a[l-1],m-2-a[l-1]));
}
signed main(){
	cin>>n>>x;
	a[0]=1;
	b[0]=1;
	for(int i=1;i<=50;i++){
		a[i]=a[i-1]*2+3;
		b[i]=b[i-1]*2+1;
	}
	cout<<sumpaty(n,x)<<endl;
	return 0;
}