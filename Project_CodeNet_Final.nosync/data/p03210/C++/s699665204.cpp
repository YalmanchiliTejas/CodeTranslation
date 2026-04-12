#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0;i < n;i++)
#define repr(i, n) for(int i = n;i >= 0;i--)
#define FOR(i, m, n) for(int i = m;i < n;i++)
#define FORR(i, m, n) for(int i = m;i >= n;i--)
#define SORT(v, n) sort(v, v+n);
#define VSORT(v) sort(v.begin(), v.end());
#define all(v) v.begin(),v.end()
#define ll long long
#define pb(a) push_back(a)
#define pf(a) push_flont(a)
#define INF 999999999
using namespace std;
typedef pair<int, int> P;
typedef pair<ll, ll> LP;
typedef pair<int, P> PP;
typedef pair<ll, LP> LPP;

int dy[]={0, 0, 1, -1, 0};
int dx[]={1, -1, 0, 0, 0};

int main(){
	int x;
	cin >> x;
	if(x == 3 || x== 5 || x==7){
		cout << "YES" <<endl;
	}
	else cout << "NO" << endl;
	return 0;
}
