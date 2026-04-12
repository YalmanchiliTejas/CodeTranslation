#include<bits/stdc++.h>
using namespace std;
#define FOR(i,l,r) for(long long i=(l);i<(r);++i)
#define REP(i,n) FOR(i,0,n)
#define int long long

signed main(){
    int N;
    cin>>N;
    int ans=0;
    int MA=0;
    REP(i,N){
        int a;
        cin>>a;
        MA=max(MA,a);
        if(a>=MA)ans++;
    }
    cout<<ans<<endl;
}