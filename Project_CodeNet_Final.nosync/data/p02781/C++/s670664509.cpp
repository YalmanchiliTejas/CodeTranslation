#pragma GCC optimize("Ofast,unroll-loops")
#include<bits/stdc++.h>
#define int long long
#define F first
#define S second
#define P pair
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define rep(i,a,b) for(int i=a;i<b;i++)
#define V vector
#define RE return
#define ALL(a) a.begin(),a.end()
#define MP make_pair
#define PB push_back
#define PF push_front
#define FILL(a,b) memset(a,b,sizeof(a))
using namespace std;
string n;int k;
int check(int x,int y){
	if(x<y)RE 0;
	int re=1;
	FOR(i,1,y)re*=x-i+1;
	FOR(i,2,y)re/=i;
	FOR(i,1,y)re*=9;
	RE re;
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>k;
	int l=n.size();
	int ans=0;
	rep(i,0,l){
		if(n[i]>'0'){
			ans=ans+check(l-i-1,k);
			ans=ans+check(l-i-1,k-1)*(n[i]-'0'-1);
			k--;
		}
		if(!k){
			ans++;break;
		}
	}
	cout<<ans;
	RE 0;
}

