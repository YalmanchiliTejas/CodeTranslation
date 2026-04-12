#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const int INF = 1e9;
const ll LINF = 1e18;
inline ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }
inline ll lcm(ll a, ll b) { return a / gcd(a, b)*b; }
template<class S,class T> ostream& operator << (ostream& out,const pair<S,T>& o){ out << "(" << o.first << "," << o.second << ")"; return out; }
template<class T> ostream& operator << (ostream& out,const vector<T>& V){ for(int i = 0; i < V.size(); i++){ out << V[i]; if(i!=V.size()-1) out << " ";} return out; }
template<class T> ostream& operator << (ostream& out,const vector<vector<T> >& Mat){ for(int i = 0; i < Mat.size(); i++) { if(i != 0) out << endl; out << Mat[i];} return out; }
template<class S,class T> ostream& operator << (ostream& out,const map<S,T>& mp){ out << "{ "; for(auto it = mp.begin(); it != mp.end(); it++){ out << it->first << ":" << it->second; if(mp.size()-1 != distance(mp.begin(),it)) out << ", "; } out << " }"; return out; }
template<typename T>vector<T> make_v(size_t a){return vector<T>(a);}
template<typename T,typename... Ts>auto make_v(size_t a,Ts... ts){return vector<decltype(make_v<T>(ts...))>(a,make_v<T>(ts...));}
template<typename T,typename V> typename enable_if<is_class<T>::value==0>::type fill_v(T &t,const V &v){t=v;}
template<typename T,typename V> typename enable_if<is_class<T>::value!=0>::type fill_v(T &t,const V &v){for(auto &e:t) fill_v(e,v);}
/*
 <url:>
 問題文============================================================
 =================================================================
 解説=============================================================
 ================================================================
 */

using ull = unsigned long long;

template<class Type>
Type solve(Type res = Type()){
    int N; cin >> N;
    vector<int> S(N),T(N);
    vector<ull> U(N),V(N);
    for(auto& in:S) cin >> in;
    for(auto& in:T) cin >> in;
    for(auto& in:U) cin >> in;
    for(auto& in:V) cin >> in;
    
    auto state = make_v<int>(N,N,64);
    
    for(int b = 0; b < 64; b++){
        
        { // 論理積が1になるパターン 積-積
            // S-Uの条件で1埋め
            for(int i = 0; i < N;i++){
                int u = (U[i]>>b)&1ull;
                if(S[i] == 0 && u == 1){
                    for(int j = 0; j < N;j++) state[i][j][b] = 1;
                }
            }
            // T-Vの条件で1埋め
            for(int j = 0; j < N;j++){
                int v = (V[j]>>b)&1ull;
                if(T[j] == 0 && v == 1){
                    for(int i = 0; i < N;i++) state[i][j][b] = 1;
                }
            }
        }
        { // 論理和が0になるパターン 和-和
            // ゼロ埋めしてるので処理不要
        }
        {
            // 論理和が1になるパターン 和1-和1 <= 1にしておいた方がいい
            // 論理積が0になるパターン 積0-積0 <= 0にしておいた方がいい
            for(int i = 0; i < N;i++){
                for(int j = 0; j < N;j++){
                    int u = (U[i]>>b)&1ull;
                    int v = (V[j]>>b)&1ull;
                    if(u == v) state[i][j][b] = u;
                }
            }
        }
        { // 論理和が1の場合を満たすものを探索
            { // 行
                for(int i = 0; i < N;i++){
                    int u = (U[i]>>b)&1ull;
                    if(S[i] && u){
                        int x = 0;
                        for(int j = 0; j < N;j++) x |= state[i][j][b];
                        if(x) continue;
                        
                        for(int j = 0; j < N;j++){
                            int v = (V[j]>>b)&1ull;
                            if(T[j] == 0 && v == 0){
                                int cnt = 0;
                                for(int ii = 0; ii < N;ii++){
                                    if(state[ii][j][b] == 0){
                                        cnt++;
                                    }
                                }
                                if(cnt >= 2){
                                    state[i][j][b] = 1;
                                    break;
                                }
                            }
                        }
                    }
                }
            }
            { // 列
                for(int j = 0; j < N;j++){
                    int v = (V[j]>>b)&1ull;
                    if(V[j] && v){
                        int x = 0;
                        for(int i = 0; i < N;i++) x |= state[i][j][b];
                        if(x) continue;
                        
                        bool ok = false;
                        for(int i = 0; i < N;i++){
                            int u = (U[i]>>b)&1ull;
                            if(S[i] == 0 && u == 0){
                                for(int jj = 0; jj < N;jj++){
                                    if(j == jj) continue;
                                    if(state[i][jj][b] == 0){
                                        ok = true;
                                        state[i][j][b] = 1;
                                        break;
                                    }
                                }
                                if(ok) break;
                            }
                        }
                    }
                }
            }
        }
        { // check
            for(int i = 0; i < N;i++){
                int u = (U[i]>>b)&1ull;
                if(S[i] == 0){
                    int x = 1;
                    for(int j = 0; j < N;j++) x &= state[i][j][b];
                    if(u != x) return -1;
                }else{
                    int x = 0;
                    for(int j = 0; j < N;j++) x |= state[i][j][b];
                    if(u != x) return -1;
                }
            }
            for(int j = 0; j < N;j++){
                int v = (V[j]>>b)&1ull;
                if(T[j] == 0){
                    int x = 1;
                    for(int i = 0; i < N;i++) x &= state[i][j][b];
                    if(v != x) return -1;
                }else{
                    int x = 0;
                    for(int i = 0; i < N;i++) x |= state[i][j][b];
                    if(v != x) return -1;
                }
            }
        }
    }
    for(int i = 0; i < N;i++){
        for(int j = 0; j < N;j++){
            ull a = 0;
            for(int k = 0; k < 64;k++){
                if(state[i][j][k]) a += 1ull << k;
            }
            cout << a << " ";
        }
        cout << endl;
    }
    return res;
}
int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(false);
    if(solve(0) == -1) cout << -1 << endl;;
    // cout << fixed << setprecision(15) << solve<ll>() << endl;
    return 0;
}
