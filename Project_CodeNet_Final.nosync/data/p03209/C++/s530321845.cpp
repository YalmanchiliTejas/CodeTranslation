#include <bits/stdc++.h>
using namespace std;
long long N,X;
int main(){
    cin>>N>>X;
    vector<long long>L(51,0);
    vector<long long>P(51,0);
    L[0]=1;P[0]=1;
    for(int i=0;i<N;i++){
        L[i+1]=L[i]*2+3;
        P[i+1]=P[i]*2+1;
    }
    long long ans=0;
    for(int i=N;i>=1;i--){
        //cout <<i<<" " <<ans<<" ";
        if(X==0)break;
        X--;
        if(X<=L[i-1])continue;
        ans+=P[i-1]+1;
        X-=L[i-1]+1;
    }
    if(X>0)ans++;
    cout<<ans<<endl;
}