#include <bits/stdc++.h>
using namespace std;
#define MD 1000000007
typedef long long int ll;

int main(){
    ll n;
    cin>>n;
    vector<ll> v(n);
    for(ll i=0;i<n;i++){
        cin>>v[i];
    }
    sort(v.begin(),v.end());
    ll ans=0,l,r;
    if(n%2==0){//偶数の場合
        l=n/2-1;
        r=n-1;
        ans+=abs(v[r]-v[l]);
        if(n!=2){
            l=0;
            ans+=abs(v[r]-v[l]);
        }
        int flag=0;
        r--;
        while(l!=n/2-1){
            if(flag==0){//rを引いた
                ans+=abs(v[r]-v[l]);
                flag=1-flag;
                l++;
            }else if(flag==1){
                ans+=abs(v[r]-v[l]);
                flag=1-flag;
                r--;
            }
        }
        ll tmp=0;
        l=0;
        r=n/2;
        tmp+=abs(v[r]-v[l]);
        if(n!=2){
            r=n-1;
            tmp+=abs(v[r]-v[l]);
        }
        flag=0;
        l++;
        while(r!=n/2){
            if(flag==1){
                tmp+=abs(v[r]-v[l]);
                flag=1-flag;
                l++;
            }else if(flag==0){
                tmp+=abs(v[r]-v[l]);
                flag=1-flag;
                r--;
            }
        }
        ans=max(ans,tmp);
    }else if(n%2==1){//奇数の場合
        l=n/2;
        r=n-1;
        ans+=abs(v[r]-v[l]);
        l=0;
        ans+=abs(v[r]-v[l]);
        int flag=0;
        r--;
        while(r!=n/2){
            if(flag==0){//rを引いた
                ans+=abs(v[r]-v[l]);
                flag=1-flag;
                l++;
            }else if(flag==1){
                ans+=abs(v[r]-v[l]);
                flag=1-flag;
                r--;
            }
        }
        ll tmp=0;
        l=0;
        r=n/2;
        tmp+=abs(v[r]-v[l]);
        r=n-1;
        tmp+=abs(v[r]-v[l]);
        flag=0;
        l++;
        while(l!=n/2){
            if(flag==1){//rを引いた
                tmp+=abs(v[r]-v[l]);
                flag=1-flag;
                l++;
            }else if(flag==0){
                tmp+=abs(v[r]-v[l]);
                flag=1-flag;
                r--;
            }
        }
        ans=max(ans,tmp);
    }
    cout<<ans<<endl;
    return 0;
}