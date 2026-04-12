#include<bits/stdc++.h>
using namespace std;
typedef  long long ll;
const int maxn=2e5+9;
int main(){
    ll n;
    ll arr[55];
    ios::sync_with_stdio(0);
    while(cin>>n){
        for(int i=0;i<n;i++)cin>>arr[i];
        ll ans=0;
        ll t=0;
        ll bu[55];
        while(1){
            memset(bu,0,sizeof(bu));
            t=0;
            for(int i=0;i<n;i++){
                if(arr[i]>n-1){
                    bu[i]=(arr[i]-n+1)/n;
                    if((arr[i]-n+1)%n){
                        bu[i]++;
                    }
                    t+=bu[i];
                }
            }
            if(!t)break;
            ans+=t;
            for(int i=0;i<n;i++){
                arr[i]-=bu[i]*n;
                arr[i]+=t-bu[i];
            }
            //for(int i=0;i<n;i++)cout<<arr[i]<<' ';cout<<endl;
            //for(int i=0;i<n;i++)cout<<bu[i]<<' ';cout<<endl;
        }
        cout<<ans<<endl;
    }

}