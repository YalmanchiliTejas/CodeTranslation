#include <bits/stdc++.h>
#include <math.h>
#include <time.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
const ll mod = 1000000007;
const int INF = 1001001001;
const ll LINF = 1001001001001001001;

int main(){
    ll n ; cin >> n;
    vector<ll> a(n);
    rep(i,n) cin >> a.at(i);
    sort(a.begin(),a.end());

    ll x = a.at(n-1);
    ll ans1 = 0;
    ll first=x,second=x,goukei=2*x;
    for(int i=0;i<(n-1)/2;i++){
        if(i%2){
            ll m = 1+(i/2);
            first = a.at(n-2*m);
            second = a.at(n-2*m-1);
            ans1 += abs(first+second-goukei); 
        }else{
            ll m = i/2;
            first = a.at(2*m);
            second = a.at(2*m+1);
            ans1 += abs(first+second-goukei);            
        }
        goukei = first+second;
    }
    if(n%4==2){
        ll y = a.at(n/2 - 1);
        ans1 += max(abs(first-y),abs(second-y));
    }else if(n%4==0){
        ll y = a.at(n/2);
        ans1 += max(abs(first-y),abs(second-y));
    }

    x = a.at(0);
    ll ans2 = 0;
    first=x,second=x,goukei=2*x;
    for(int i=0;i<(n-1)/2;i++){
        if(i%2==0){
            ll m = 1+(i/2);
            first = a.at(n-2*m+1);
            second = a.at(n-2*m);
            ans2 += abs(first+second-goukei); 
        }else{
            ll m = i/2;
            first = a.at(2*m+1);
            second = a.at(2*m+2);
            ans2 += abs(first+second-goukei);            
        }
        goukei = first+second;
    }
    if(n%4==0){
        ll y = a.at(n/2 - 1);
        ans2 += max(abs(first-y),abs(second-y));
    } else if(n%4==2){
        ll y = a.at(n/2);
        ans2 += max(abs(first-y),abs(second-y));
    }
  
    //cout << ans1 << ans2 << endl;
    cout << max(ans1,ans2) << endl;
}
