#include <bits/stdc++.h>
using namespace std;
//#define MOD 1000000007
#define MOD 998244353
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
    int N,K;
    char S[11],e;
    cin >> N;
    for(int i=1;i<=N;i++){
        cin >> S[i];
    }
    cin >> K;
    
    e=S[K];
    
    for(int i=1;i<=N;i++){
        if(S[i]==e){
            cout << S[i];
        }else{
            cout << '*';
        }
    }
    cout << endl;
    
    
    return 0;
}
