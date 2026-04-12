// -*- compile-command: "g++ -g -Wno-return-type -Wall -Wextra -DLOCAL -std=c++11 -D_GLIBCXX_DEBUG c.cpp -oc && ./c " -*-
#include <bits/stdc++.h>
using namespace std;
using LL=long long;
#define int LL
#define vc vector
#define pb push_back
#define pr pair
#define fi first
#define se second
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(),(v).end()
#define f(i,n) for(int i=0;i<(n);i++)
#define fr(i,n) for(int i=(n);i--;)
#define fv(i,v) f(i,sz(v))

main(){
	ios::sync_with_stdio(0),cin.tie(0);
	int n;
	cin>>n;
	vc<int> a(n);
	f(i,n) cin>>a[i];
	vc<int> b(n);
	int j=(n-1)/2;
	f(i,n){
		b[j]=a[i];
		if(!(i&1)) j+=i+1;
		else j-=i+1;
	}
	if(!(n&1)) reverse(all(b));
	f(i,n) cout<<b[i]<<" \n"[i+1==n];
}
