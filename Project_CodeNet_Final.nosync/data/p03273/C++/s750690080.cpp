#include <bits/stdc++.h>
#define FOR(i, begin, end) for(int i=(begin);i<(end);i++)
#define REP(i, n) FOR(i,0,n)
#define IFOR(i, begin, end) for(int i=(end)-1;i>=(begin);i--)
#define IREP(i, n) IFOR(i,0,n)
#define SORT(a) sort(a.begin(), a.end())
#define REVERSE(a) reverse(a.begin(), a.end())
#define int long long
#define INF 1000000000000000
using namespace std;

typedef vector<int> vec;
typedef vector<vec> mat;
typedef pair<int, int> Pii;

template<typename T>
void readvec(vector<T> &a);
void readindex(vector<int> &a);



signed main(){

    int H, W; cin >> H >> W;
    vector<string> S(H);
    REP(i, H) cin >> S[i];

    REP(i, H){
        bool w = true;
        REP(j, W) if(S[i][j] == '#') w = false;
        if(w) REP(j, W) S[i][j] = 'x';
    }
    REP(j, W){
        bool w = true;
        REP(i, H) if(S[i][j] == '#') w = false;
        if(w) REP(i, H) S[i][j] = 'x';
    }

    REP(i, H){
        bool l = false;
        REP(j, W){
            if(S[i][j] != 'x'){
                l = true;
                cout << S[i][j];
            }
        }
        if(l) cout << endl;
    }

    
    return 0;
}


template<typename T>
void readvec(vector<T> &a){
    REP(i, a.size()){
        cin >> a[i];
    }
}
void readindex(vector<int> &a){
    REP(i, a.size()){
        cin >> a[i];
        a[i]--;
    }
}