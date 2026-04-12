#include "bits/stdc++.h"
using namespace std;
#define PB push_back
#define MP make_pair
#define REP(i,n) for(int i=0;i<(n);i++)
int main(){
    int n;
    long long a[50];
    cin>>n;
    REP(i,n)cin>>a[i];
    long long ans=0;
    bool f=true;
    while(f){
        f=false;
        long long sum=0;
        long long b[n];
        REP(i,n){
            b[i]=a[i]/n;
            sum+=b[i];
            ans+=b[i];
            a[i]-=b[i]*n;
        }
        REP(i,n)a[i]+=sum-b[i];
        REP(i,n)if(a[i]>=n)f=true;
    }
    cout<<ans<<endl;

}