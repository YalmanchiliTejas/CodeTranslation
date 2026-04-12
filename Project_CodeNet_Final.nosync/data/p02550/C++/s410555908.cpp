#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
#define cinf(n,x) for(int i=0;i<(n);i++)cin>>x[i];
#define ft first
#define sc second
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define all(v) (v).begin(),(v).end()
#define LB(a,x) lb(all(a),x)-a.begin()
#define UB(a,x) ub(all(a),x)-a.begin()
#define mod 1000000007
//#define mod 998244353
#define FS fixed<<setprecision(15)
using namespace std;
typedef long long ll;
const double pi=3.141592653589793;
template<class T> using V=vector<T>;
using Graph = vector<vector<int>>;
using P=pair<ll,ll>;
typedef unsigned long long ull;
typedef long double ldouble;
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline void out(T a){ cout << a << '\n'; }
void YN(bool ok){if(ok) cout << "Yes" << endl; else cout << "No" << endl;}
//void YN(bool ok){if(ok) cout << "YES" << endl; else cout << "NO" << endl;}


const ll INF=1e18;
const int mx=200005;
//abc179

int main(){
    cin.tie(0);ios::sync_with_stdio(false);
    ll n,x,m;
    cin>>n>>x>>m;
    if(x==0) out(0);
    else if(x==1) out(n);
    else{
        V<ll> a;
        ll cnt=0;
        ll tmp=x;
        set<ll> st;
        ll ans=0;
        bool f=0;
        while(true){
            if(cnt==0){
                st.insert(tmp);
                a.pb(tmp);
                cnt++;
            }else{
                tmp=(tmp*tmp)%m;
                if(st.count(tmp)||tmp==0){
                    if(tmp==0){
                        for(ll cur:st) ans+=cur;
                    }else{
                        ll id=0;
                        ll c=0;
                        ll sum=0;
                        for(id=0;id<a.size();id++){
                            if(tmp==a[id]){
                                for(int i=id;i<a.size();i++){
                                    sum+=a[i];
                                }
                                break;
                            }
                            c+=a[id];
                        }
                        n-=id;
                        ans+=c;
                        ans+=sum*(n/(a.size()-id));
                        rep(i,n%(a.size()-id)) ans+=a[id+i];
                    }
                    break;
                }
                cnt++;
                st.insert(tmp);
                a.pb(tmp);
                if(cnt==n){
                    for(ll ff:st) ans+=ff;
                    break;
                }
            }
            
            //out("ok");
        }
        
        
        
        out(ans);
    }
}
//ペナルティ出しても焦らない　ACできると信じろ！！！
//どうしてもわからないときはサンプルで実験　何か見えてくるかも
//頭で考えてダメなら紙におこせ！！
/*
V,P(大文字)使用不可
乗算などの際にオーバーフローに注意せよ！
(適切にmodをとれ　にぶたんで途中で切り上げろ)
制約をよく読め！
{
    ・全探索できるなら全探索しろ
    ・異常な制約ならそこに注目
}
stringの計算量(扱い)注意
コーナー注意！(特に数値が小さいものについては要検証)
N行出力のときは'¥n'
グリッド上では行先が範囲内におさまるかif文で確認(RE注意)
if文ではちゃんと比較演算子==を使え('='でもエラー出ない)
配列(vector)の大きさが0か1以上かで場合分けせよ(RE注意)
(vector<int> a(m)でm==0というものはできない)
modはなるべく最後に取れ！
doubleを扱うときには(abs)ではなく'fabs'!!!
*/