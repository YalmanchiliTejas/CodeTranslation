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

template<class Type>
Type solve(Type res = Type()){
    int r,g,b; cin >> r >> g >> b;
    int x = 100*r + 10*g + b;

    if(x%4 == 0){
        cout << "YES" << endl;
    }else{
        cout << "NO" << endl;
    }
    return res;
}

//template<class Type>
//Type solve(Type res = Type()){
//    string s; cin >> s;
//    string ans = "";
//    int num = 0;
//    char pre = ' ';
//
//    for(auto c:s){
//        if(c == pre){
//            num++;
//        }else{
//            if(num != 0){
//                ans += pre;
//                ans += to_string(num);
//            }
//            pre = c;
//            num = 1;
//        }
//    }
//    ans += pre;
//    ans += to_string(num);
//
//    cout << ans << endl;
//    return res;
//}

//template<class Type>
//Type solve(Type res = Type()){
//    string S; cin >> S;
//    int N; cin >> N;
//
//    for(int i = 0; i < N;i++){
//        int l,r; cin >> l >> r;
//        string s = S.substr(l-1,r-l+1);
//        reverse(s.begin(),s.end());
//        S = S.substr(0,l-1) + s + S.substr(r);
//    }
//
//    cout << S << endl;
//    return res;
//}

//template<class Type>
//Type solve(Type res = Type()){
//    string X; cin >> X;
//    while(X.size()){
//        if(X.size() >= 2){
//            if(X[X.size()-2] == 'c' && X[X.size()-1] == 'h'){
//                X.pop_back();
//                X.pop_back();
//                continue;
//            }
//        }
//        if(X.back() == 'o' || X.back() == 'k' || X.back() == 'u'){
//            X.pop_back();
//            continue;
//        }
//        break;
//    }
//
//    if(X.size()) cout << "NO" << endl;
//    else cout << "YES" << endl;
//    return res;
//}

//template<class Type>
//Type solve(Type res = Type()){
//    int N; cin >> N;
//    int a,b; cin >> a >> b;
//    a--; b--;
//    int M; cin >> M;
//    vector<vector<int>> G(N);
//    for(int i = 0; i < M;i++){
//        int x,y; cin >> x >> y;
//        x--; y--;
//
//        G[x].push_back(y);
//        G[y].push_back(x);
//    }
//
//    const ll MOD = 1e9+7;
//    vector<ll> dp(N,0);
//    vector<ll> dist(N,LINF);
//    dp[a] = 1;
//    dist[a] = 0;
//    priority_queue<pll> pq;
//    pq.push(pll(0,a));
//    while(pq.size()){
//        ll d,n; tie(d,n) = pq.top(); pq.pop();
//        if(dist[n] < d) continue;
//        for(auto next:G[n]){
//            if(dist[next] > dist[n] + 1){
//                dist[next] = dist[n] + 1;
//                pq.push(pll(-dist[next],next));
//            }
//        }
//    }
//
//    pq.push(pll(0,a));
//    while(pq.size()){
//        ll d,n; tie(d,n) = pq.top(); pq.pop();
//        for(auto next:G[n]){
//            if(dist[next] == dist[n] + 1){
//                dp[next] += dp[a];
//                dp[next] %= MOD;
//                pq.push(pll(-dist[next],next));
//            }
//        }
//    }
//    cout << dp[b] << endl;
//    return res;
//}

//int d[4] = {1,0,-1,0};
//template<class Type>
//Type solve(Type res = Type()){
//    ll H,W,T; cin >> H >> W >> T;
//    vector<vector<char>> masu(H+2,vector<char>(W+2,'@'));
//
//    pll S,G;
//    for(int i = 1; i <= H;i++) for(int j = 1; j <= W; j++){
//        cin >> masu[i][j];
//        if(masu[i][j] == 'S'){
//            S = pll(i,j);
//            masu[i][j] = '.';
//        }
//        if(masu[i][j] == 'G'){
//            G = pll(i,j);
//            masu[i][j] = '.';
//        }
//    }
//
//    ll l = 1, r = 5LL*INF;
//    while(r-l>1){
//
//        ll m = (l+r)/2;
//
//        vector<vector<ll>> dist(H+2,vector<ll>(W+2,LINF));
//        queue<pll> q;
//        q.push(S);
//        dist[S.first][S.second] = 0;
//
//        while(q.size()){
//            ll x,y; tie(x,y) = q.front(); q.pop();
//
//            for(int k = 0; k < 4;k++){
//                ll nx = x + d[k];
//                ll ny = y + d[k^1];
//
//                if(masu[nx][ny] == '@') continue;
//
//                ll cost = 1;
//                if(masu[nx][ny] == '#') cost = m;
//
//                if(dist[nx][ny] > dist[x][y] + cost){
//                    dist[nx][ny] = dist[x][y] + cost;
//                    q.push(pll(nx,ny));
//                }
//            }
//        }
//
//        if(dist[G.first][G.second] <= T){
//            l = m;
//        }else{
//            r = m;
//        }
//    }
//    cout << l << endl;
//    return res;
//}

//template<class Type>
//Type solve(Type res = Type()){
//    ll N,M; cin >> N >> M;
//
//    vector<vector<int>> G(N,vector<int>(N,INF));
//    for(int i = 0; i < N;i++) G[i][i] = 0;
//    for(int i = 0; i < M;i++){
//      int a,b,c; cin >> a >> b >> c;
//      a--; b--;
//      G[a][b] = G[b][a] = c;
//    }
//
//    for(int i = 0; i < N;i++){
//       for(int j = 0; j < N;j++){
//         for(int k = 0; k < N;k++){
//           G[j][k] = min(G[j][k],G[j][i] + G[i][k]);
//         }
//       }
//     }
//
//    int ans = INF;
//    for(int i = 0; i < N;i++){
//      int t_cost = 0;
//      for(int j = 0; j < N;j++){
//        if(i == j) continue;
//        t_cost = max(t_cost,G[i][j]);
//      }
//      ans = min(ans,t_cost);
//    }
//    cout << ans << endl;
//
//    return res;
//}
//
//template<class Type>
//Type solve(Type res = Type()){
//    ll N,M,R; cin >> N >> M >> R;
//    vector<ll> r(R); for(auto& in:r){ cin >> in; in--; }
//    vector<vector<ll>> G(N,vector<ll>(N,LINF));
//    for(int i = 0; i < N;i++) G[i][i] = 0;
//    for(int i = 0; i < M;i++){
//        ll A,B,C; cin >> A >> B >> C;
//        A--; B--;
//        G[A][B] = G[B][A] = min(G[A][B],C);
//    }
//
//    for(int i = 0; i < N;i++) for(int j = 0; j < N;j++) for(int k = 0; k < N;k++) G[j][k] = min(G[j][k],G[j][i] + G[i][k]);
//
//    vector<vector<ll>> dp(R,vector<ll>(1<<R,LINF));
//    for(int i = 0 ; i < R;i++) dp[i][1<<i] = 0;
//    for(int j = 0; j < (1<<R);j++){
//        for(int i = 0; i < R;i++){
//            if(dp[i][j] == LINF) continue;
//            for(int k = 0; k < R; k++){
//                if((j>>k)&1) continue;
//                dp[k][j|(1<<k)] = min(dp[k][j|(1<<k)],dp[i][j] + G[r[i]][r[k]]);
//            }
//        }
//    }
//
//    ll ans = LINF;
//    for(int i = 0; i < R;i++) ans = min(ans,dp[i][(1<<R)-1]);
//    cout << ans << endl;
//    return res;
//}

int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(false);
    solve(0);
    // cout << fixed << setprecision(15) << solve<ll>() << endl;
    return 0;
}
