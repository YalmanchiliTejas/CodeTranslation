#pragma region Macros
#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define REPR(i, n) for(int i=(n); i>=0; --i)
#define FOR(i, n, m) for(int i=(m), i##_len=(n); i<i##_len; ++i)
#define EACH(i, v) for(const auto& i : v)
#define ALL(x) (x).begin(),(x).end()
#define ALLR(x) (x).rbegin(),(x).rend()
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
template<class Value>using vec = vector< Value >;
using ll = long long;
using P = pair< long long, long long >;
#define fi first
#define se second
#define el endl
#pragma endregion
void Main();

int main(){
    std::cin.tie(nullptr);
    std::cout << std::fixed << std::setprecision(15);
    Main();
    return 0;
}

void Main(){
    int H, W;
    cin >> H >> W;
    vec<string> mp(H);
    vec<bool> cols(W, true), rows(H, true);
    REP(i, H){
        cin >> mp[i];
        REP(j, W){
            if(mp[i][j] != '.'){
                rows[i] = false;break;
            }
        }
    }
    REP(j, W){
        REP(i, H){
            if(mp[i][j] != '.'){
                cols[j] = false;break;
            }
        }
    }
    REP(i, H){
        if(rows[i]){
            continue;
        }
        REP(j, W){
            if(cols[j]){
                continue;
            }
            cout << mp[i][j];
        }
        cout << el;
    }
}

