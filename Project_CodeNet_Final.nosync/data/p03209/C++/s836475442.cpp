#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define fi first
#define se second
#define pb push_back
#define all(v) (v).begin(),(v).end()
ll mod = 1000000007;
ll INF = 1000000099;



signed main(){
    ll n,k,ans=0;
    cin>>n>>k;
    k--;
    vector<ll> v(n);

    ll r=((1ll<<(n+2))-4),l=0;

    while(n>0){
        ll mid=(l+r)/2;

        if(n==1){
            if(k==l){
            }else if(k==r){
                ans+=-1+(1ll<<(n+1));
            }else if(k==mid){
                ans+=(1ll<<n);
            }else if(k<mid){
                ans++;
            }else{
                ans+=3;
            } 
            break; 
        }

        if(k==l){
            //cout << "TEST1" << endl;
            break;
        }else if(k==r){
            ans+=-1+(1ll<<(n+1));
            //cout << "TEST2" << endl;
            break;
        }else if(k==mid){
            ans+=(1ll<<n);
            //cout << "TEST3" << endl;
            break;
        }else if(k<mid){
            l++;
            r=mid-1;
            //cout << "TEST4" << endl;
        }else{
            ans+=(1ll<<(n));
            l=mid+1;
            r--;
        }
        n--;   
        
    }

    
    
    cout << ans << endl;
}
