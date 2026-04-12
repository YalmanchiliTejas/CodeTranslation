#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for (int i=0;i<(n);i++)
#define int long long 


signed main(){
    int N,K;
    cin >> N >> K;
    int Ans=0;
    if(K==0){
        cout << N*N << endl;
        return 0;
    }
    REP(i,N+1){
        if(i<=K)continue;
        
        Ans+=  ((int)((N+1)/i)) * (i-K);
        if((N+1)%i>K){Ans+=((N+1)%i-K);}
        //cout << i << " "  << Ans << endl;
        
    }
    cout <<Ans << endl;
    return 0;
}
