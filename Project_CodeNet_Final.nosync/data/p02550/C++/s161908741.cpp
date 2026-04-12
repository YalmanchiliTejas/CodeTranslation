#include<bits/stdc++.h>
using namespace std;
int main(){
    long long n,x,m,ans=0;
    cin>>n>>x>>m;
    int used[m]={};
    while(used[x]==0){
        used[x]=1;
        ans+=x;
        n--;
        if(n==0){
            cout<<ans<<endl;
            return 0;
        }
        x=x*x%m;
    }
    long long syuki=1,start=x;
    long long syuki_sum=x;
    x=x*x%m;
    while(x!=start){
        syuki_sum+=x;
        x=x*x%m;
        syuki++;
    }
    ans+=(n/syuki)*syuki_sum;
    n%=syuki;
    while(n){
        ans+=x;
        n--;
        x=x*x%m;
    }
    cout<<ans<<endl;
    return 0;
}