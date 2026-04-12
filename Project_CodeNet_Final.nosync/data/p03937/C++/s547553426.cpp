#include <bits/stdc++.h>

#define int long long

#define REP(i,n) for(int i=0;i<n;i++)
#define FOR(i,m,n) for(int i=m;i<n;i++)
#define FORR(i,m,n) for(int i=m;i>=n;i--)
#define pb(x) push_back(x) 
#define SORT(x) sort((x).begin(),(x).end())
#define INF 99999999999
 
using namespace std;

int32_t main(){
    int h, w;
    cin >> h >> w;
    string s[h];
    REP(i, h) cin >> s[i];

    REP(i, h){
        REP(j, w){
            bool f=0;
            FOR(k, j+1, w){
                if(s[i][k]=='#') f=1;
            }
            FOR(k, i+1, h){
                if(f && s[k][j]=='#'){
                    cout << "Impossible" << endl;
                    return 0;
                }
            }
        }
    }

    cout << "Possible" << endl;
}