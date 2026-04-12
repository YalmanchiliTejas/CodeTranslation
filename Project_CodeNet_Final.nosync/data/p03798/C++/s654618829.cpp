#include <bits/stdc++.h>
using namespace std;
#define repr(i,a,b) for(int i=a;i<b;i++)
#define rep(i,n) for(int i=0;i<n;i++)
#define reprrev(i,a,b) for(int i=b-1;i>=a;i--) // [a, b)
#define reprev(i,n) reprrev(i,0,n)
typedef long long ll;
typedef unsigned long long ull;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }

/* attention
    long longのシフト演算には気をつけよう
    タイポした時のデバッグが死ぬほどきつくなるので変数名は最低3字くらい使った方がいいかも
    sizeは(int)とキャストしよう
    ごちゃごちゃ場合分けを考える前に全探索は考えましたか？
    詰まった時に、別の分野の問題として考え直す（これdpでは？、グラフとしてみればいいのでは？）
    多くの問題はパターンマッチだが、パターンに落とし込むまでが難しく、そのための訓練としてわからない問題をあれこれ色々な角度から考察してみるのではないか
    cin.tie(0);
    ios::sync_with_stdio(false);<- これら、printfとかと併用しない方が良さそう

*/

const ll mod = 1e9+7;

void chmod(ll &M){
    if(M >= mod) M %= mod;
    else if(M < 0){
        M += (abs(M)/mod + 1)*mod;
        M %= mod;
    }
}

int getl(int i, int N) { return i==0? N-1:i-1; };
int getr(int i, int N) { return i==N-1? 0:i+1; };

/* <--------------------------------------------> */



int main(void){
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n; cin >> n;
    string s; cin >> s;
    string ans(n, '.');

    bool flg=false;
    rep(bit, 1<<2){
        // initialization
        rep(i, 2){
            if(bit&1<<i) ans[i]='S';
            else ans[i]='W';
        }
        // struct
        repr(i, 1, n-1){
            if(ans[i]=='S'){
                if(s[i]=='o') ans[i+1] = ans[i-1]=='S'? 'S':'W';
                else ans[i+1] = ans[i-1]=='S'? 'W':'S';
            }
            else{
                if(s[i]=='o') ans[i+1] = ans[i-1]=='S'? 'W':'S';
                else ans[i+1] = ans[i-1]=='S'? 'S':'W';
            }
        }
        // check
        bool ok=true;
        rep(i, n){
            if(ans[i]=='S'){
                if(s[i]=='o' && ans[getl(i, n)]!=ans[getr(i, n)]) ok=false;
                if(s[i]=='x' && ans[getl(i, n)]==ans[getr(i, n)]) ok=false;
            }
            else{
                if(s[i]=='o' && ans[getl(i, n)]==ans[getr(i, n)]) ok=false;
                if(s[i]=='x' && ans[getl(i, n)]!=ans[getr(i, n)]) ok=false;
            }
        }
        if(ok){
            flg=true; break;
        }
    }
    if(flg) cout << ans << endl;
    else cout << -1 << endl;

    return 0;
}
