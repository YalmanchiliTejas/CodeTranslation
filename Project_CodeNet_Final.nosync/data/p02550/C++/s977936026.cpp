#include <bits/stdc++.h>
#define pb push_back
#define Int long long
using namespace std;

Int N,M,K;
Int H,W;
Int X,Y,Z,C;

const int MAXN=500005;
vector<Int> A;
vector<int> adj[MAXN];
Int perform(Int x){
    return (x*(x+1))/2LL;
}



int main()
{
    cin>>N>>X>>M;
    vector<long long> pref;
    pref.pb(X);
    long long sum=X;
    vector<int> pos(M,-1);
    pos[X]=0;
    for(Int i=1;i<N;++i){
        X=1LL*(X*X)%M;
        pref.pb(pref.back()+X);
        sum+=X;
        if(pos[X]==-1) pos[X]=i;
        else{
            Int length=i-pos[X];
            Int cycles=max(0LL,(N-i-2)/length);
            if(!cycles) continue;
            sum+=(pref[i]-pref[pos[X]])*cycles;
            i+=length*cycles;
        }
        
    }
    cout<<sum<<"\n";
    
}