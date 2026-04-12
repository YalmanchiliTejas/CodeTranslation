// In The Name Of God
#include<bits/stdc++.h>
using namespace std;

#define F first
#define S second
#define mp make_pair
#define pb push_back
#define int long long
#define ll long long
#define for2(a,b,c) for(int a = b; a < c; a++)
#define setp cout << fixed << setprecision(7)
#define endl "\n"
#define minit(a,b) a = min(a,b)
#define maxit(a,b) a = max(a,b)
#define PII pair<int,int>
#define Vec vector<int>
#define error(x) cerr << #x << " = " << (x) << endl;

const ll inf = ~0ull/4;
const int maxn = 210000;

/////////////////////////////////////////////////////////////////////

int a[50];

int32_t main()
{
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int n; cin >> n;
	for2(i,0,n)  cin >> a[i];
		//a[i] = 1e16 + 1000;

	int k = 0;
	while(1){
		bool found = 0;
		for2(i,0,n) if(a[i] >= n){
			for2(j,0,n) if(j != i) a[j] += a[i]/n;
			k += a[i]/n;
			a[i] %= n;
			found = 1;
		}
		if(!found) break;
	}
	cout << k << endl;
	return 0;

}