#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define mod 1000000007

int main(){
    int N;
    cin>>N;
    vector<ll> A(N);
    for(int i=0;i<N;i++) cin>>A[i];
    sort(A.begin(),A.end(),greater<ll>());
    
    if(N%2==0){
        ll res=0;
        for(int i=0;i<N/2-1;i++) res+=A[i]*2;
        res+=A[N/2-1];
        res-=A[N/2];
        for(int i=N/2+1;i<N;i++) res-=A[i]*2;
        cout<<res<<endl;
    }
    else{
        ll res1=0;
        for(int i=0;i<N/2-1;i++) res1+=A[i]*2;
        res1+=A[N/2-1]+A[N/2];
        for(int i=N/2+1;i<N;i++) res1-=A[i]*2;
        
        ll res2=0;
        for(int i=0;i<N/2;i++) res2+=A[i]*2;
        res2-=A[N/2]+A[N/2+1];
        for(int i=N/2+2;i<N;i++) res2-=A[i]*2;
        cout<<max(res1,res2)<<endl;
    }
}
