#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; i++)
#define all(x)(x).begin(), (x).end() // 昇順ソート
#define rall(v)(v).rbegin(), (v).rend() // 降順ソート
#define INF 1 LL << 60
typedef long long int LL;
typedef long long int ll;
#define pll pair < ll, ll >
#define F first
#define S second
const int MOD = 1000000007;
template < class T > bool chmax(T & a,const T & b) { if (a < b) { a = b; return true; } return false; }
template < class T > bool chmin(T & a,const T & b) { if (a > b) { a = b; return true; } return false; }
// 任意のlogは　対数の底の変換を使う    log(N) / log(任意の底)

int main() {
    LL N,X,M;cin >> N >> X >> M;

    vector<LL> stc;
    LL ct = 0;
    map<LL,int> m;
    LL ans = 0;
    m[X]++;
    stc.push_back(X);

    while(ct < N-1){
        X *= X;
        X %= M;
        if(m[X] != 0){
            LL ind = -1;
            LL limit = stc.size();

//            cout << limit  << " limit"<< endl;

            rep(i,limit){
                if(stc[i] == X){
                    ind = i;
                    break;
                }
            }
            LL sum = 0;
            
            rep(i,limit){
                sum += stc[i];
            }
            ans += sum;

//            cout << ans << " ans simple" << endl;

            LL p_sum = 0;
            for(LL i = ind;i < limit;i++)p_sum += stc[i];  // indからlimitまでの和

            LL r_sum = ((N-ind)/(ct - ind + 1) -1) * p_sum;

            ans += r_sum;   // roop sum






/*
            cout << ans << " " << ct << endl;
            cout << "AAAAAA" << endl;
*/
            LL lim = (N-ind) - ((N-ind)/(ct-ind+1) * (ct-ind+1));
/*
            cout << lim << "lim" << endl;
            cout << ind << "ind" << endl;
*/
            for(LL i = ind;i < ind + lim ;i++){
                ans += stc[i];
            }
            break;
        }
        m[X]++;
        stc.push_back(X);
        ct++;
    }   

    if(ans == 0){
        for(auto t : stc)ans += t;
    }

//    for(auto t : stc)cout << t << endl;
    cout << ans << endl;
}