#include <iostream>
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(void){
    int ok=1;
    ll n,k,ans=0;
    cin>>n>>k;
    while(ok&&n!=0){
        ll nn=pow(2,n);
        if(k==2*nn-1){
            ans+=nn;
            ok=0;
        }
        else if(k==1){
            ok=0;
        }
        else if(k==4*nn-3){
            ok=0;
            ans+=2*nn-1;
        }
        else if(k<2*nn-1){
            k-=1;
            n-=1;
        }
        else if(k>2*nn-1){
            k=k-2*nn+1;
            n-=1;
            ans+=nn;
        }
    }
    cout<<ans+(n==0)<<endl;
}
