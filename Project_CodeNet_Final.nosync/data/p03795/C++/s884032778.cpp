#include "bits/stdc++.h"
using namespace std;

#define pb push_back
#define mp make_pair
#define F(i, a, n) for(int i=a;i<n;i++)
#define REP(i, n) F(i, 0, n)
#define REP1(i, n) for(int i=1;i<=n;i++)
#define REV(i, n) for(int i=n;i>=0;i--)
#define PTR(it, x) for(auto it=x.begin();it!=x.end();++it)
#define MOD 1000000007

typedef unsigned long long ll;

const ll MAX = 1e6 + 5;

int n;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin>>n;
	cout<<n*800 - n/15*200;
	return 0;
}