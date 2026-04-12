#include<bits/stdc++.h>
using namespace std;
int main(){
    long long int ans=0,n,k;
    cin>>n>>k;
    if(k==0){
        cout<<n*n;
        return 0;
    }
    for(int i=n;i>k;--i)
        ans+=(n/i)*(i-k) + ((n/i)*i + k <=n ? n-(n/i)*i - k+1 : 0);
    cout<<ans;
    return 0;
}
