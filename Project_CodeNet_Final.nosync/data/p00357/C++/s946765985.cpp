#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define INF 10000000000000009
//#define INF 9223372036854775807
typedef long long ll;
#define REP(i,n) for(int i=0;i<(n);++i)
#define OREP(i,n) for(int i=1;i<=(n);++i)
#define ORREP(i,n) for(int i=(n);i>=1;--i)
#define ZREP(i,n) for(int i=1;i<(n);++i)
#define RREP(i,n) for(int i=(n)-1;i>=0;--i)
#define rollcall cout<<"I'm Sucu."<<endl;
#define YES(s) s?cout << "YES" << endl:cout << "NO" << endl
#define Yes(s) s?cout << "Yes" << endl:cout << "No" << endl
#define Taka(s) s?cout << "Takahashi" << endl:cout << "Aoki" << endl
#define out(s,t,u) s?cout << t << endl:cout << u << endl
#define int ll
#define Endl endl

signed main(){
    int N;
    int d[314514];
    cin >> N;
    REP(i,N){
        cin >> d[i];
    }
    int R=d[0];
    OREP(i,N-1){
        if(10*i>R){cout << "no" << endl;return 0;}
        R=max(R,i*10+d[i]);
    }
    int L=d[N-1];
    OREP(i,N-1){
        if(10*i>L){cout << "no" << endl;return 0;}
        L=max(L,i*10+d[N-1-i]);
    }
    cout << "yes" << endl;
    return 0;
}   
