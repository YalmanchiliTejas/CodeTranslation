#pragma GCC optimize ("Ofast")
#include "bits/stdc++.h"
#include "ext/pb_ds/assoc_container.hpp"
#include "ext/pb_ds/tree_policy.hpp"
using namespace __gnu_pbds;
using namespace std;
typedef long long int ll;
#define int long long int
#define pb push_back
#define fi first
#define se second
#define deb cerr << "Line no." << __LINE__
#define fr(i, a, b) for(int i = a; i <= b; i++)
#define all(x) x.begin(), x.end()
#define IO ios :: sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define pii pair<int,int>
#define sz(x) (int)x.size()
const int mod = 1e9 + 7;
const int mod1 = 998244353;
typedef long double f80;
#ifndef LOCAL
#define endl '\n'
#endif

template<typename T>
using ordered_set = tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int rand(int l, int r){
	uniform_int_distribution<int> uid(l, r);
	return uid(rng);
}
int pwr(int a,int b){
	int ans = 1;
	while(b){
		if(b & 1) ans = (ans * a) % mod;
		a = (a * a) % mod;
		b >>= 1;
	}
	return ans;
}
int sz;
const int NN = 101;
class matrix{
public:
    ll mat[NN][NN];
    matrix(){
        for(int i = 0; i < NN; i++)
            for(int j = 0; j < NN; j++)
                mat[i][j] = 0;
        sz = NN;
    }
    inline matrix operator * (const matrix &a){
        matrix temp;
        for(int i = 0; i < sz; i++)
            for(int j = 0; j < sz; j++){
                for(int k = 0; k < sz; k++){
                temp.mat[i][j] += (mat[i][k] * a.mat[k][j]) % mod;
                if(temp.mat[i][j] >= mod)
                    temp.mat[i][j] -= mod;
                }
            }
        return temp;
    }
    inline matrix operator + (const matrix &a){
        matrix temp;
        for(int i = 0; i < sz; i++)
            for(int j = 0; j < sz; j++){
                temp.mat[i][j] = mat[i][j] + a.mat[i][j] ;
                if(temp.mat[i][j] >= mod)
                    temp.mat[i][j] -= mod;
            }
        return temp;
    }
    inline matrix operator - (const matrix &a){
        matrix temp;
        for(int i = 0; i < sz; i++)
            for(int j = 0; j < sz; j++){
                temp.mat[i][j] = mat[i][j] - a.mat[i][j] ;
                if(temp.mat[i][j] < mod)
                    temp.mat[i][j] += mod;
            }
        return temp;
    }
    inline void operator = (const matrix &b){
        for(int i = 0; i < sz; i++)
            for(int j = 0; j < sz; j++)
                mat[i][j] = b.mat[i][j];
    }
    inline void print(){
        for(int i = 0; i < sz; i++){
            for(int j = 0; j < sz; j++){
                cout << mat[i][j] << " ";
            }
            cout << endl;
        }
    }
};
matrix pow(matrix a,ll k){
    matrix ans;
    for(int i = 0; i < sz; i++)
        ans.mat[i][i] = 1;
    while(k){
        if(k & 1)
            ans = ans * a;
        a = a * a;
        k >>= 1;
    }
    return ans;
}
const int N = 10005;
int dp[2][N][105];
string s;
void solve(){
	cin >> s;
	s = '0' + s;
	int d;
	cin >> d;
	int n = s.size();
	dp[1][0][0] = 1;
	fr(j, 0, n - 2){
		fr(i, 0, 1){
			fr(l, 0, d - 1){
				if(!dp[i][j][l]) continue;
				if(i == 0){
					fr(k, 0, 9){
						dp[0][j + 1][(l + k) % d] += dp[i][j][l];
						dp[0][j + 1][(l + k) % d] %= mod;
					}
				}
				else{
					int val = s[j + 1] - '0';
					fr(k, 0, val - 1){
						dp[0][j + 1][(l + k) % d] += dp[i][j][l];
						dp[0][j + 1][(l + k) % d] %= mod;
					}
					dp[1][j + 1][(l + val) % d] += dp[i][j][l];
					dp[1][j + 1][(l + val) % d] %= mod;
				}
			}
		}
	}
	cout << (dp[0][n - 1][0] + dp[1][n - 1][0] + mod - 1) % mod;
}
signed main(){
  	IO;
  	#ifdef LOCAL
		freopen("inp.txt","r", stdin);
		// freopen("out.txt", "w", stdout);
	#endif
 	clock_t clk = clock();
  	int t = 1;
  	// cin >> t;
  	fr(tt, 1, t){
    	solve();
  	}
  	cerr << endl << (double)(clock() - clk) / CLOCKS_PER_SEC;
  	return 0;
}