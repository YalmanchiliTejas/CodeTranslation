#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ll n,l,r;
    while(1){
        cin>>n>>l>>r;
        if(n==0&&r==0&&l==0)break;
        ll a[n];
        for(ll i=0;i<n;i++)cin>>a[i];
        ll res = 0;
        bool flag=false;
        for(ll i=l;i<=r;i++){
            flag=false;
            for(ll j=0;j<n;j++){
                if(i%a[j]==0){
                    if((j+1)%2==1){
                        res++;
                        //cout<<i<<endl;
                        flag=true;
                    }else{
                        flag=true;
                    }
                    break;
                }
            }
            if(!flag){
                if(n%2==0)res++;
            }
        }
        cout<<res<<endl;
    }
}
