#include<bits/stdc++.h>
#define ll long long
#define ALL(v) (v).begin(),(v).end()
#define REP(i,p,n) for(int i=p;i<(int)(n);++i)
#define rep(i,n) REP(i,0,n)
#define dump(a) (cerr << #a << "=" << (a) << endl)
#define DUMP(list) cout << "{ "; for(auto nth : list){ cout << nth << " "; } cout << "}" << endl;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }


using namespace std;

int main(){
    int N;
    cin >> N;
    ll s[N];
    rep(i, N){
        cin >> s[i];
    }

    ll ans = 0;
    REP(i,1, N){
        ll res = 0;
        ll c = i;
        ll tmp1 = 0;
        ll tmp2 = N-1;
        ll res1 = 0;
        if ((N - 1) % c == 0) {
//            cout << tmp1 << " 1 " << tmp2 << endl;
            while(tmp1 < tmp2 ) {

                res1 += s[tmp1] + s[tmp2];
                chmax(res, res1);
                tmp1 += c;
                tmp2 -= c;
            }
            chmax(ans, res);
        } else {
//            cout << tmp1 << " 2 " << tmp2 << endl;
            while(tmp1 < N - 1 - c && tmp2 > c) {

                res1 += s[tmp1] + s[tmp2];
                chmax(res, res1);
                tmp1 += c;
                tmp2 -= c;
            }
            chmax(ans, res);
        }

//        cout << ans << endl;
    }

    cout << ans << endl;
}