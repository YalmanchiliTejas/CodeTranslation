#include <bits/stdc++.h>

using namespace std;
using ll =long long;
typedef pair<int,int> P;
#define SORT(a) sort((a).begin(),(a).end())
#define REV(a) reverse((a).begin(),(a).end())
#define For(i, a, b)    for(int i = (a) ; i < (b) ; ++i)
#define rep(i, n)       For(i, 0, n)
#define debug(x)  cerr << #x << " = " << (x) << endl;
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }

void coY() {cout <<"Yes"<<endl;}
void coN(){cout <<"No"<<endl;}
 
//Write From this Line

//const ll mod = 1e9+7;
//const ll mod = 998244353;

const int dy[] = {0,0,1,-1};
const int dx[] = {1,-1,0,0};
int main()
{
	ll n, x, m;
	cin >> n >> x >> m;
	map<ll, int> mp;
	mp[x] = 1;

	vector<ll> a(2);
	a[1] = x;

	ll ans = x;
	for(ll i = 2; i <= n; i++){
		a.push_back(a[i-1]*a[i-1]);
		a[i] %= m;

		if(mp[a[i]]){
			ll start = mp[a[i]]; 
			ll score = 0;
			for(ll j = start; j < i; j++) score += a[j]; // 1周期のスコア
			ll rpsz = i - 1 - mp[a[i]] + 1;
			ll sz = n - i + 1;

			ans += sz / rpsz * score;
			ll nokori = sz % rpsz;
			while(nokori--){
				ans += a[start++];
			}
			break;
		}
		mp[a[i]] = i;
		ans += a[i];
	}
	cout << ans << endl;
}
