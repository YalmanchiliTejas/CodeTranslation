#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define pi 3.1415926536
#define pb push_back
#define N 1000000007
#define M 998244353
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define nrep(i,a,b) for(int i=a;i>=b;i--)
#define pl pair<ll,ll>
#define pi pair<int,int>
#define pll pair< ll, pair<ll,ll> > 
#define pii pair< int, pair<int,int> >
int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll l,t,T,x,y,z,n;
    cin>>n;
    ll a[n+5];
    rep(i,1,n) cin>>a[i];
    x = 0,y=0;
    rep(i,1,n){
    	x+=a[i];
    	x%=N;
	}
	rep(i,1,n){
		x= (x - a[i] + N)%N;
		y+=x*a[i];
		y%=N;
	}
	cout<<y;
}