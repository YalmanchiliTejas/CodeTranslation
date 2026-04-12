#include <bits/stdc++.h>
#define FOR(i, begin, end) for(int i=(begin);i<(end);i++)
#define REP(i, n) FOR(i,0,n)
#define IFOR(i, begin, end) for(int i=(end)-1;i>=(begin);i--)
#define IREP(i, n) IFOR(i,0,n)
#define SORT(a) sort(a.begin(), a.end())
#define REVERSE(a) reverse(a.begin(), a.end())
#define Lower_bound(v, x) distance(v.begin(), lower_bound(v.begin(), v.end(), x))
#define Upper_bound(v, x) distance(v.begin(), upper_bound(v.begin(), v.end(), x))
#define int long long
#define INF 1000000000000000000
using namespace std;

typedef vector<int> vec;
typedef vector<vec> mat;
typedef pair<int, int> Pii;

template<typename T>
void readvec(vector<T> &a);
void readindex(vector<int> &a);



signed main(){

    int H, W; cin >> H >> W;
    vector<string> A(H);
    REP(i, H) cin >> A[i];

    vec s(H, -1), e(H, -1);
    REP(i, H){
        REP(j, W){
            if(A[i][j] == '#'){
                s[i] = j;
                break;
            }
        }
        if(s[i] == -1){
            cout << "Impossible";
            return 0;
        }
        FOR(j, s[i], W){
            if(A[i][j] == '.'){
                e[i] = j - 1;
                break;
            }
        }
        if(e[i] == -1) e[i] = W - 1;
        FOR(j, e[i] + 2, W){
            if(A[i][j] == '#'){
                cout << "Impossible";
                return 0;
            }
        }
        //cout << s[i] << "," << e[i] << endl;
    }
    bool f = true;
    REP(i, H - 1) if(e[i] != s[i + 1]) f = false;
    if(f) cout << "Possible";
    else cout << "Impossible";
    
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