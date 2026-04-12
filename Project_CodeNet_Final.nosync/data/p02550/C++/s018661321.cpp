#include<bits/stdc++.h>
#define all(v) v.begin(),v.end()
using namespace std;
int main(){
    long long n,x,m,l[100005]={},sum[100005]={},ans=0,c=1000000,d;
    cin>>n>>x>>m;
    for(int i=0;i<m && i<n ;i++){
        if(i!=0)
            sum[i]+=x+sum[i-1];
        else
            sum[i]=x;
        l[i]=x;
        ans+=x;
        x*=x;
        x%=m;
        if(i!=n-1){
        for(int j=0;j<i;j++){
            if(x==l[j]){
                c=j;
                d=i;
                n-=d;
                n--;
                break;
            }
        }
        }
        if(c!=1000000)
            break;
    }
    if(c!=1000000){
        long long a=n/(d-c+1),b=sum[d]-sum[c-1];
        ans+=a*b;
        n%=(d-c+1);
        for(int i=c;i<n+c;i++){
            ans+=l[i];
        }
    }
    cout<<ans<<endl;
  return(0);
}