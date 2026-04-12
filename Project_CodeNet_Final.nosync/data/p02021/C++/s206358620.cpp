#include <bits/stdc++.h>
#define REP(i, a, n) for(ll i=a; i<n; i++)
#define RREP(i, a, n) for(ll i=n-1; i>=a; i--)
typedef long long ll;
const ll mod =1e9+7;
const ll inf =1e18;
using namespace std;


int main(){
    ll n;
    ll a[101];
    ll sum=0;
    cin>>n;
    REP(i, 0, n){
        cin>>a[i];
        sum+=a[i];
    }

    ll work=sum/n;
    RREP(i, 0, work+1){
        ll cnt=0;
        bool flag=true;
        REP(i, 0, n){
            cnt+=a[i];
            if(cnt>=work){
                cnt-=work;
            }
            else{
                flag=false;
                break;
            }
        }

        if(flag){
            cout<<work<<endl;
            break;
        }
        work--;
    }
    return 0;
}
