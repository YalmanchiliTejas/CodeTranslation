#include<bits/stdc++.h>
#include <map>
#include <set>
#include <vector>
#include <algorithm>
#include <iostream>
#include <bitset>
#include <cassert>
#include <queue>
#include <stack>
#include <iomanip>
#include <math.h>
#include <time.h>
using namespace std;
#define rep(i, n) for (ll i = 0; i < (ll)n; i++)
#define repf(i, a, b) for (ll i = (ll)a; i < (ll)b; i++)
#define repr(i, a, b) for (ll i = (ll)a; i > (ll)b; i--)
#define all(v) (v).begin(), (v).end()
#define mp(a, b) make_pair(a, b)
#define pb(x) push_back(x)
#define eb(x) emplace_back(x)
#define F first
#define S second
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<ld, ld> pdd;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef vector<int> vii;
typedef vector<vii> vvii;
const ll mod = 1e9 + 7;
const int infi = 1147483600;
const ll infl = 1e17;
const char ENDL = '\n';
//cout << fixed << setprecision(17) << res << endl;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;cin>>n;
    vii cnt(26, infi);
    rep(xx,n){
        string s;
        cin >> s;
        vii cnti(26, 0);
        rep(i,s.size()){
            cnti[s[i] - 'a']++;
        }
        rep(i,26){
            cnt[i] = min(cnt[i], cnti[i]);
        }
    }
    string ans;
    rep(i,26){
        rep(j,cnt[i]){
            ans += (char)('a' + i);
        }
    }
    cout << ans << ENDL;
}