#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define INF 100000000000000009
typedef long long ll;
#define REP(i,n) for(int i=0;i<(n);++i)
#define OREP(i,n) for(int i=1;i<=(n);++i)
#define ZREP(i,n) for(int i=1;i<(n);++i)
#define YES(s) s?cout << "YES" << endl:cout << "NO" << endl
#define Yes(s) s?cout << "Yes" << endl:cout << "No" << endl
#define out(s,t,u) s?cout << t << endl:cout << u << endl
#define int ll
#define Endl endl
 
 
signed main(){
    int N;
    int H[57];
    cin >> N;
    REP(i,N){cin >> H[i];}
    int now=0;
    int Ans=0;
    REP(i,N){
        if(H[i]>=now){
            Ans++;
            now=H[i];
        }
    }
    cout << Ans << endl;
    return 0;
}
