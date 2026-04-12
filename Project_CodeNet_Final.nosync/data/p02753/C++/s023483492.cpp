#include<bits/stdc++.h>

#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")

using namespace std;
#define ll long long
#define pb push_back
#define mp make_pair
#define ull unsigned long long
#define rep(n) for(ll i = 0 ; i<n ; i++) 
#define repd(n) for(ll i = n-1 ; i>=0 ; i--)
#define MOD 1000000007

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	string s; cin>>s;
  bool a=0,b=0;
  for(auto i:s) if(i=='A') a=1; else b=1;
  if(a && b) cout<<"Yes"; else cout<<"No";
	return 0;
}
