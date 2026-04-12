#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> l_l;
typedef pair<int , int> i_i;
typedef vector<ll> vel;
typedef vector<int> vei;
typedef vector<char> vec;
typedef vector<bool> veb;
typedef vector<string> ves;
typedef vector<vector<ll>> ve_vel;
typedef vector<vector<int>> ve_vei;
typedef vector<vector<char>> ve_vec;
typedef vector<vector<bool>> ve_veb;
typedef vector<vector<string>> ve_ves;
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define rep1(i,n) for(int i=1;i<(int)(n);i++)
#define rep2(i,n) for(int i=2;i<(int)(n);i++)
#define repk(i,k,n) for(int i=k;i<(int)(n);i++)
#define fs first
#define sc second
#define pub push_back
#define puf push_front
#define pob pop_back
#define all(a) a.begin(),a.end()
#define rall(a) a.rbegin(),a.rend()
#define maxel(a) *max_element(all(a))
#define minel(a) *min_element(all(a))
#define acc accumulate
#define EPS (1e-7)
#define INF (1e9)
#define PI (acos(-1))
#define mod (1000000007)
template<class T> bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T> bool chmin(T &a, const T &b) { if (a>b) { a=b; return 1; } return 0; }

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);

    int n; cin >> n;
    ves S(n); rep(i,n) cin >> S[i];
    ve_vei check(n, vei(26,0));

    rep(i,n){
        rep(j,S[i].size()) {
            check[i][ S[i][j] - 'a' ]++;
        }
    }

    vei final_check(26);

   

    vei ans(26,100);
    if(n == 1) {
        rep(i,26) ans[i] = check[0][i];
        rep(i,26) {
            rep(j,ans[i]){
                cout << (char)(i + 'a') ;
            }
        }
        cout << endl;
        return 0;
    }

    rep(i,26) {
        int temp;
        rep(j,n-1) {
            temp = min(check[j][i], check[j+1][i]);
            ans[i] = min(ans[i], temp);
        }
    }
    rep(i,26) {
        rep(j,ans[i]){
            cout << (char)(i + 'a') ;
        }
    }
    cout << endl;
    return 0;
}
