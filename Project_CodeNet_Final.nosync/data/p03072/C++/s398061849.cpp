#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    ll n,i,ans=0,max;
    cin>>n;
    ll arr[n];
    for(i=0;i<n;i++)
        cin>>arr[i];
    max=arr[0];
    for(i=1;i<n;i++){
        if(arr[i]>=max)
            ans+=1;
        if(arr[i]>max)
            max=arr[i];
    }
    cout<<ans+1<<endl;
    return 0;
}
