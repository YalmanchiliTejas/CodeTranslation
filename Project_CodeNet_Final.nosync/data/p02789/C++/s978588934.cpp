#include "bits/stdc++.h"

using namespace std;
using VI = vector<int>;
using VPI = vector<pair<int, int>>;
using LL = long long;

#define FOR(a,n) for(int i=a;i<n;i++)
#define rFOR(a,n) for(int i=n-1;i>=a;i--)
#define IN(n,a) for(int i=0;i<n;i++) cin>>a[i]
#define pIN(n,t) for(int i=0;i<n;i++){int a,b; cin>>a>>b; t.emplace_back(a,b);}
#define SORT(a) sort(a.begin(), a.end())
#define ALL(a) a.begin(), a.end()

int main()
{
	int n, m;
	cin >> n >> m;

	if (n == m) cout << "Yes";
	else cout << "No";
}