#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
#define all(x) (x).begin(),(x).end()
#define pll pair<ll,ll>
#define pii pair<int,int>
#define rep(i,n) for(int i=0;i<n;i++)
#define For(i,a,b) for(int i=a;i<b;i++)
#define sz(x) ((ll)(x).size())
#define pb push_back
#define mp make_pair
#define bit(n) (1LL<<(n))
#define F first
#define S second
#define debug(x) cerr << x << endl
#define Complex complex<double>
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};
const ll INF = 1LL<<60;
const ll mod = (int)1e9 + 7;

/*
テストケース全てに目を通す
テストケースが2個以下だったらなんかある
N最小のコーナーケースがないか調べる
制約をしっかりと確認する（1からNまでの順列、全て異なる値などの制約も含め）
制約のn*mとn,mを読み違えない
操作の逆順を考える
オーバーフローしないか確かめる
Codeforcesではscanfを使う
modの引き算には+modをする
エラー出力は消す
エラー出力を消せ！！！！！
数値の区切り位置を誤読しない
木はn-1ノード
関数単位で調べる
cout << fixed;
cout << setprecision(n) << ans;
 */

int main() {
    string s;
    cin >> s;
    int k;
    cin >> k;
    int n=s.length();
    int dp0[n][k+3];
    int dp1[n][k+3];
    rep(i,n){
        rep(j,k+1){
            dp0[i][j]=0;
            dp1[i][j]=0;
        }
    }
    rep(i,n){
        if(!i){
            int num=s[0]-'0';
            dp0[0][0]=1;
            dp0[0][1]=num-1;
            dp1[0][1]=1;
        }
        else{
            int num=s[i]-'0';
            if(num){
                rep(j,k+2){
                    dp0[i][j]+=dp0[i-1][j]+dp1[i-1][j];
                    dp0[i][j+1]+=dp0[i-1][j]*9+dp1[i-1][j]*(num-1);
                    dp1[i][j+1]+=dp1[i-1][j];
                }
            }
            else{
                rep(j,k+2){
                    dp0[i][j]+=dp0[i-1][j];
                    dp0[i][j+1]+=dp0[i-1][j]*9;
                    dp1[i][j]+=dp1[i-1][j];
                }
            }
        }
    }    
    cout << dp0[n-1][k]+dp1[n-1][k];
	cerr << dp1[0][1];
    
}

/*
*/

