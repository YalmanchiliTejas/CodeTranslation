#include <bits/stdc++.h>
using namespace std;

#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define ALL(obj) (obj).begin(), (obj).end()
#define INF 1e9
#define LINF 1e18
typedef unsigned long long ll;



int main() {
    int N; cin >> N;
    vector<ll> S(N),T(N),U(N),V(N);
    REP(i,N) cin >> S[i];
    REP(i,N) cin >> T[i];
    REP(i,N) cin >> U[i];
    REP(i,N) cin >> V[i];
    vector<vector<vector<int>>> G(N,vector<vector<int>>(N,vector<int>(64,-1)));

    REP(n,64){
        //cout << (1ll<<n) << endl;
        REP(h,N){
            REP(w,N){
                bool a,b,c,d;
                a = S[h];
                b = U[h]&(1ll<<n);
                c = T[w];
                d = V[w]&(1ll<<n);
                //cout << a << b << c << d << endl;
                if((!a)&&b){
                    if(c && (!d)){
                        cout << -1 << endl;
                        return 0;
                    }else{ 
                        G[h][w][n] = 1;
                    }
                }
                else if((!a) && (!b)){
                    if((!c)&&d) G[h][w][n] = 1;
                    else if(!d) G[h][w][n] = 0;
                    else{
                        G[h][w][n] = -2;
                    }
                }else if(a&&b){
                    if(d) G[h][w][n] = 1;
                    else if(c&&(!d)) G[h][w][n] = 0;
                    else{
                        G[h][w][n] = -3;
                    }
                }
                else if(a&&(!b)){
                    if((!c)&&d){
                        cout << -1 << endl;
                        return 0;
                    }
                    else{
                        G[h][w][n] = 0;
                    }
                }
            }
        }

        // REP(h,N){
        //     REP(w,N){
        //         cout << G[h][w][0] << " ";
        //     }
        //     cout << endl;
        // }


        //これで1周終わり、残りの矛盾を解決していきたい
        //まず横だけ見て、限界のところを埋める
        REP(h,N){
            bool a,b;
            a = S[h];
            b = U[h]&(1ll<<n);
            if((!a)&&(!b)){//最低1つは0が欲しい時
                int cnt = 0;
                int pos = 0;
                bool ok = false;
                REP(w,N){
                    //全部1だとまずい
                    //1個でも0があればBreak
                    if(G[h][w][n] == 0){
                        ok = true;
                    }
                    else if(G[h][w][n] == -2){
                        pos = w;
                        cnt++;
                    }
                }
                if(ok) continue;//問題ない時は以下の処理を飛ばす

                if(cnt==0){//矛盾してれば終わり
                    cout << -1 << endl;
                    return 0;
                }else if(cnt==1){//限界なら置くべきものを置く
                    G[h][pos][n] = 0;
                }
            }else if(a&&b){//最低1つは1が欲しい時
                int cnt = 0;
                int pos = 0;
                bool ok = false;
                REP(w,N){
                    //全部0だとまずい
                    //1個でも1があればBreak
                    if(G[h][w][n] == 1){
                        ok = true;
                    }
                    else if(G[h][w][n] == -3){
                        pos = w;
                        cnt++;
                    }
                }
                if(ok) continue;//問題ない時は以下の処理を飛ばす

                if(cnt==0){//矛盾してれば終わり
                    cout << -1 << endl;
                    return 0;
                }else if(cnt==1){//限界なら置くべきものを置く
                    G[h][pos][n] = 1;
                }
            }
        }


        //縦でも同じことをする
        REP(w,N){
            bool c,d;
            c = T[w];
            d = V[w]&(1ll<<n);
            if((!c)&&(!d)){//最低1つは0が欲しい時
                int cnt = 0;
                int pos = 0;
                bool ok = false;
                REP(h,N){
                    //全部1だとまずい
                    //1個でも0があればBreak
                    if(G[h][w][n] == 0){
                        ok = true;
                    }
                    else if(G[h][w][n] == -3){
                        pos = h;
                        cnt++;
                    }
                }
                if(ok) continue;//問題ない時は以下の処理を飛ばす

                if(cnt==0){//矛盾してれば終わり
                    cout << -1 << endl;
                    return 0;
                }else if(cnt==1){//限界なら置くべきものを置く
                    G[pos][w][n] = 0;
                }
            }else if(c&&d){//最低1つは1が欲しい時
                int cnt = 0;
                int pos = 0;
                bool ok = false;
                REP(h,N){
                    //全部0だとまずい
                    //1個でも1があればBreak
                    if(G[h][w][n] == 1){
                        ok = true;
                    }
                    else if(G[h][w][n] == -2){
                        pos = h;
                        cnt++;
                    }
                }
                if(ok) continue;//問題ない時は以下の処理を飛ばす

                if(cnt==0){//矛盾してれば終わり
                    cout << -1 << endl;
                    return 0;
                }else if(cnt==1){//限界なら置くべきものを置く
                    G[pos][w][n] = 1;
                }
            }
        }

        //ここまでで解決してない場合は各列、行に2つ以上余地がある
        //そのため横向きだけ考えればよく、2部グラフのように01を埋めていけば実現可能！
        int x0 = 0;
        int y0 = 0;
        REP(h,N){
            int x = 0;
            int y = 0;
            bool xok = false;
            bool yok = false;
            REP(w,N){
                if(G[h][w][n] == -2){
                    xok = true;
                    G[h][w][n] = x0^x;
                    x= 1-x;
                }
                if(G[h][w][n] == -3){
                    yok = true;
                    G[h][w][n] = y0^y;
                    y= 1-y;
                }
            }
            if(xok) x0 = 1-x0;
            if(yok) y0 = 1-y0;
        }
    }


    REP(h,N){
        REP(w,N){
            ll ans = 0;
            REP(n,64){
                if(G[h][w][n]) ans += 1ll<<n;
            }
            cout << ans << " ";
        }
        cout << endl;
    }
    return 0;
}