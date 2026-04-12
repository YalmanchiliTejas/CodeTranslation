#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> l_l;
typedef vector<ll> vel;
typedef vector<int> vei;
typedef vector<char> vec;
typedef vector<bool> veb;
typedef vector<string> ves;
typedef vector<vector<int>> ve_vei;
typedef vector<vector<char>> ve_vec;
typedef vector<vector<string>> ve_ves;
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define rep1(i,n) for(int i=1;i<(int)(n);i++)
#define rep2(i,n) for(int i=2;i<(int)(n);i++)
#define fs first
#define sc second
#define pub push_back
#define pob pop_back
#define all(a) a.begin(),a.end()
#define rall(a) a.rbegin(),a.rend()
#define maxel(a) max_element(all(a))
#define acc accumulate
#define EPS (1e-7)
#define INF (1e9)
#define PI (acos(-1))
#define mod (1000000007)

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);

    int H,W; cin >> H >> W;
    ve_vec a(H,vec(W));
    rep(i,H) rep(j,W) cin >> a[i][j];
    veb row(H,false);
    veb col(W,false);
    rep(i,H) {
        rep(j,W){
            if(a[i][j] == '#') {
                row[i] = true;
                col[j] = true; 
            }
        }
    }
    rep(i,H) {
        if(row[i]){
            rep(j,W){
                if(col[j]){
                    cout << a[i][j];
                }
            }
            cout << endl;
        }
    }

}