#include<bits/stdc++.h>
using namespace std;
#define int long long
#define f(z) for(int i=1;i<=z;i++)
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define vi vector<int>
#define pb push_back
#define si set<int>
#define mod  1000000007
#define cl(n,m) (int)(ceil(double(n)/double(m)))
#define T() int TT; cin>>TT; while(TT--)
#define P pair<int,int>
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

signed main(){
	int n ,k;
	string s ;
	cin>>n ;
	cin>>s >>k;
	for(int i=0 ;i<n ;i++){
		if(s[i]!=s[k-1]) s[i] = '*' ;
	}
	cout<<s ;
}
