#include <bits/stdc++.h>
#define vsort(v) sort(v.begin(), v.end())
#define rvsort(v) sort(v.begin(), v.end(), greater<ll>())
#define vfind(v, target) find(v.begin(), v.end(), target)
#define notFound(v, target) (vfind(v, target) == v.end())
#define maxIndex(v) max_element(v.begin(), v.end()) - v.begin()
#define maxElement(v) *max_element(v.begin(), v.end())
#define minIndex(v) min_element(v.begin(), v.end()) - v.begin()
#define minElement(v) *min_element(v.begin(), v.end())
#define ll long long
#define rep(i, s, g) for (ll i = (s); i < (g); i++)
#define MOD 1000000007
using namespace std;

int main()
{
  ll N; cin >> N;
  string S;
  vector<vector<ll>> alpha(N, vector<ll>(26, 0));
  rep(i, 0, N) {
  	cin >> S;
    rep(j, 0, S.size()) {
    	alpha[i][S[j] - 'a']++;
    }
  }
  rep(j, 0, 26) {
  	ll max = 100000;
    rep(i, 0, N) {
    	if (max > alpha[i][j]) {
        	max = alpha[i][j];
        }
    }
    rep(i, 0, max) {
    	cout << char('a' + j);
    }
  }
}