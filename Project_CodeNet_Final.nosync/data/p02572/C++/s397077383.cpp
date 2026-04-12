#include <bits/stdc++.h>
 
using namespace std;
 
#define MOD 1000000007
#define MN 200000
#define ll long long 
 
int main(){
    int n;
    cin >>n;
    ll c;
    ll r=0;
    ll m=0;
    for(int i=0;i<n;i++){
        cin >>c;
        m=((c*c)%MOD+m)%MOD;
        r=(c%MOD+r)%MOD;
    }
    r=(r*r)%MOD;
    r=(r-m+MOD)%MOD;
    r*=(MOD+1)/2;
    r%=MOD;
    cout <<r;
 
}
