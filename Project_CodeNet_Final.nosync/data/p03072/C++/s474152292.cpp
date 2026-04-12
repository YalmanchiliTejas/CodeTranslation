#include "bits/stdc++.h"
using namespace std;

using ll = long long;
using ld = long double;
using P = pair<int, int>;
using vi = vector<int>;
using vl = vector<ll>;
ld EPS = 1e-12;
int INF = numeric_limits<int>::max() / 2;
ll LINF = numeric_limits<ll>::max() / 2;
int MOD = 1e9 + 7;
#define rep(i,n) for(int i = 0; i < n; i++)
#define all(obj) (obj).begin(), (obj).end()
#define debug(x) cerr << #x << ": " << x << '\n'

vector<vector<pair<int, int> > > edge;//edge[i][j] firstがiからj番目のノード、secondがその重み
vector<int> d(100005,INF);

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    int ans = 0;
	int n;
	int last = 0;
	cin >> n;
	rep(i,n){
		int a;
		cin >> a;
		if(a >= last){
			ans++;
			last = a;
		}
	}
	cout << ans << endl;
}