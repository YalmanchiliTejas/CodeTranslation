#include <bits/stdc++.h>
#include <math.h>
#define rep(i, n) for(int i = 0; i < (n); i++)
#define rrep(i, n) for(int i = 0; i <= (n); i++)
using namespace std;
typedef long long ll;
 
const ll INF = 1LL<<62;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
// 多次元 vector 生成
template<class T>
vector<T> make_vec(size_t a){
    return vector<T>(a);
}
template<class T, class... Ts>
auto make_vec(size_t a, Ts... ts){
  return vector<decltype(make_vec<T>(ts...))>(a, make_vec<T>(ts...));
}

const int MOD = 1000000007;




int main(){
    
    int H, W;
    cin >> H >> W;

    vector<string> a(H);
    rep(i,H) cin >> a[i];

    vector<string> ans;
    rep(i,H){
        string tmp = "";
        rep(j,W){
            bool isVerticalOK = false;
            rep(k,H){
                if (a[k][j] == '#'){
                    isVerticalOK = true;
                }
            }
            bool isHorizontalOK = false;
            rep(k,W){
                if (a[i][k] == '#'){
                    isHorizontalOK = true;
                }
            }
            if (isVerticalOK && isHorizontalOK) tmp += a[i][j];
        }
        if (tmp != ""){
            ans.push_back(tmp);
        }
    }

    rep(i,ans.size()){
        cout << ans[i] << endl;
    }
}

