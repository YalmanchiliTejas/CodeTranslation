#include<bits/stdc++.h>
#define all(v) v.begin(),v.end()
using namespace std;
int main(){
    long long n,a[200005];
    cin>>n;
    long long ans=0,sum[200005]={};
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=n-1;i>=0;i--){
        if(i!=n-1){
            sum[i]=sum[i+1]+a[i];
        }
        else{
            sum[i]=a[i];
        }
        sum[i]%=(1000000000+7);
    }
    for(int i=0;i<n-1;i++){
        ans+=a[i]*sum[i+1]%(1000000000+7);
    }
    cout<<ans%(1000000000+7)<<endl;
  return(0);
}