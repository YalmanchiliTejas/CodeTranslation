#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
#define ll long long 
#define pb push_back
//#define mp make_pair
#define fr first
#define sc second
#define MAX ((ll)(1e15+100))
#define ARRS ((ll)(1e6+100))
#define MOD ((ll)(1e9+7))
#define EP ((double)(1e-9))
#define EPS ((double)(1e-8))
#define pb push_back
#define PI ((double)3.141592653)

ll n,m,k,p,q,h;
ll d,b;
ll a[ARRS];
	string s;

int main(){
	ios::sync_with_stdio(0);
	cin>>n>>k;
	ll pas=0;
	for(int b=k+1; b<=n; b++){
		pas+=(b-k)*(n/b);
		if(n%b>=k)pas+=(n%b-k+1);
		if(!k)pas--;
		//cout<<b<<" " <<pas<<endl;
	}
	cout<<pas;
}
