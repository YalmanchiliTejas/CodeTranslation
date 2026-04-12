#include "bits/stdc++.h"
using namespace std;

#define pb push_back
#define mp make_pair
#define F(i, a, n, b) for(int i=a;i<n;i+=b)
#define REVF(i, a, b, c) for(int i=a;i>=b;i-=c)
#define REP(i, n) F(i, 0, n, 1)
#define REP1(i, n) F(i, 1, n+1, 1)
#define REV(i, n) REVF(i, n, 0, 1)
#define PTR(it, x) for(auto it=x.begin();it!=x.end();++it)
#define MOD 1000000007

typedef unsigned long long ll;

const int MAX = 1e6 + 5;

int n,m;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin>>n>>m;
	if(m == n)
		cout<<"Yes";
	else
		cout<<"No";
	return 0;
}