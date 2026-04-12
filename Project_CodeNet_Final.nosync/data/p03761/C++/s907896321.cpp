#include <bits/stdc++.h>
#define MODNum 1000000007
#define REP(type, i, a, b) for( type i = a; i < b; i++ )
typedef long long ll;

using namespace std;

int main (void) {
    int N;
    cin >> N;
    map<char,int> mp;
    string S, T;
    cin >> S;
    REP(int,j,0,S.size()) mp[S.at(j)]++;
    REP(int,i,1,N){
        map<char,int> mp1;
        cin >> S;
        REP(int,j,0,S.size()) mp1[S.at(j)]++;
        for ( auto&x : mp ){
            mp[x.first] = min( mp1[x.first], x.second );
        }
        //for ( auto&x : mp1 ) cout << mp[x.first] << endl;
    }
    for ( auto&x : mp ){
        REP(int,i,0,x.second) T += x.first;
    }
    cout << T << endl;
    return 0;
}
