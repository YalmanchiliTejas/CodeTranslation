

#include <bits/stdc++.h>
//#pragma GCC diagnostic warning "-std=c++11"
using namespace std;
#define ll long long 
#define pb push_back
//#define mp make_pair
#define fr first
#define sc second
#define MAX ((ll)(1e18+100))
#define MX ((ll)(1e6+90))
#define ARRS ((ll)(3e5+100))
#define MOD ((ll)(1e9+7))
#define EP ((double)(1e-9))
#define EPS ((double)(1e-8))
#define pb push_back
#define PI ((double)3.141592653)
#define LG 16

ll n,m;
pair<ll,ll>  a[ARRS];
ll pas[ARRS];

int main(){
	cin>>n;
	for(int i=0; i<n; i++){
		cin>>a[i].fr;
		a[i].sc=i;
	}

	ll m=n/2;
	m--;

	sort(a,a+n);

	for(int i=0; i<n; i++){
		if(i<=m)
			pas[a[i].sc]=a[m+1].fr;
		else pas[a[i].sc]=a[m].fr;
	}

	for(int i=0; i<n; i++)
		cout<<pas[i]<<endl;
}
