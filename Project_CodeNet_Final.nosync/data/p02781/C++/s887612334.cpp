// ░░░░░░░░( •̪●)░░░░░░░░░░░░░░░░░░░░░░░░
// ░░░░░░███████ ]▄▄▄▄▄▄▄▄▃░░░▃░░░░ ▃░
// ▂▄▅█████████▅▄▃▂░░░░░░░░░░░░░░░░░
// [███████████████████].░░░░░░░░░░░░░░
// ◥⊙▲⊙▲⊙▲⊙▲⊙▲⊙▲⊙◤...░░░░░░░░░░░░

//PointBlank's code (⌐■_■)

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
 
ll power(ll x, ll y); 
#define repp(I, A, B) for(int I = A; I <= B; I++)
#define rep(I, A, B) for(int I = A; I < B; I++)
#define rrep(I, B, A) for(int I = B; I >= A; I--)
#define pb emplace_back
#define ff first
#define ss second
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
#define LB lower_bound
#define UB upper_bound
#define MP make_pair
#define mem(A, B) memset(A, B, sizeof(A));
#define mem0(A) memset(A, 0, sizeof(A));
#define quickio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define debug(this) cerr<<"> "<<#this<<" : "<<this<<"\n"
#define bitcount(n) __builtin_popcountll(n)
#define in_edges(M) repp(I, 1, M){ll A, B; cin >> A >> B; v[A].pb(B), v[B].pb(A);}
#define in_edges2(M) repp(I, 1, M){ll A, B; cin >> A >> B; v[A].pb(B);}
#define endl "\n"

const ll MOD = 1000000007;

ll ncr(ll n, ll r){
    if(n < r) return 0ll;
    ll res = 1;
    rep(i, 0, r) res *= (n - i);
    repp(i, 2, r) res /= i;
    return res;
}
 
int main() //PointBlank's code ¯\_(ツ)_/¯
{
    string s;
    cin >> s;
    int n = s.size();
    int k;
    cin >> k;
    s += '0';

    ll x = n, y = n;
    rep(i, 1, n) if(s[i] != '0'){x = i; break;}
    rep(i, x + 1, n) if(s[i] != '0'){y = i; break;}

    ll res = ncr(n, k);
    rep(i, 0, k) res *= 9;

    if(k == 1) res -= (9 - s[0] + '0');

    if(k == 2){
        if(x == n) res -= (10 - s[0] + '0')*(n-1)*9;
        else
            res -= (9 - s[x] + '0'),
            res -= (x - 1)*9,
            res -= (9 - s[0] + '0')*(n-1)*9;
    }

    if(k == 3){
        if(x == n && y == n) res -= (10 - s[0] +'0')*ncr(n-1, 2)*9*9;
        if(x < n && y == n){
            res -= (10 - s[x] + '0')*(n - x - 1)*9,
            res -= (x - 1) * (n - x) * 81,
            res -= (9 - s[0] + '0')*ncr(n-1, 2)*81;
        }
        if(x < n && y < n){
            res -= (9 - s[y] + '0'),
            res -= (y - x - 1)*9,
            res -= (9 - s[x] + '0')*(n - x - 1)*9,
            res -= (x - 1)*9*(n - x)*9,
            res -= (9 - s[0] + '0')*ncr(n-1, 2)*9*9;
        }
    }

    ll ans = 0;
    rep(i, 2, n-1) ans += (i*(i-1))/2 * 9 * 9 * 9;
	ans += max(0,(s[0]-'0'-1) * (n-1) * (n-2) / 2 * 9 * 9);
    rep(i, 1, n){
		if(s[i] != '0'){
			ans += max(0,(s[i]-'0'-1) * (n-i-1) * 9);
			ans += max(0,(n-i-1)*(n-i-2) / 2 * 9 * 9);
			for(int j=i+1;j<n;j++){
				if(s[j] != '0'){
					
					ans += s[j]-'0';
					ans += max(0,(n-j-1)*9);
					
					break;
				}
			}
			break;
		}
	}

    if(k == 3 && x < n && y == n) cout << ans;
    else cout << res;
}

ll power(ll x, ll y)
{ 
    ll res = 1; x %= MOD;
    while(y > 0){if(y & 1) res = (res*x) % MOD; y = y>>1, x = (x*x) % MOD;} 
    return res; 
}