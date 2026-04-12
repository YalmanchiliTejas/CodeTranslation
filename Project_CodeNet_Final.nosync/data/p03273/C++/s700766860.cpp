#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define REP(i,n) for(ll i=0; i<(n); i++)
#define REP2(i,x,n) for(ll i=x; i<(n); i++)
const long long INF = numeric_limits<long long>::max();
template<class T> inline bool chmin(T& a, T b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}
template<class T> inline bool chmax(T& a, T b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}
int main()
{
    ll H, W;
    cin >> H >> W;
    vector<string> maps(H);
    for ( ll i = 0; i < H; ++ i ){
        cin >> maps[i];
    }

    while(1){
        bool isRemove = false;
        for ( ll i = 0; i < maps.size(); ++ i ){
            if ( maps[i].find('#') == string::npos ){
               maps.erase(maps.begin()+i);
               i--;
               isRemove = true;
            }
        }

        if ( maps.size() == 0 ) break;
        for ( ll i = 0; i < maps[0].size(); ++ i ){
            bool findS = false;
            for ( ll j = 0; j < maps.size(); ++ j ){
                findS |= maps[j][i] == '#';
            }
            if ( !findS ){
                for ( ll j = 0; j < maps.size(); ++ j ){
                    maps[j].erase(maps[j].begin() + i );
                }
                isRemove = true;
            }
        }
        if ( !isRemove )    break;
    }

    for ( const auto& m : maps ){
        cout << m << endl;
    }


    return 0;
}