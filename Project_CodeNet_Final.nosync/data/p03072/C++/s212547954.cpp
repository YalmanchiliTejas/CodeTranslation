#include<bits/stdc++.h>
#define ll          long long int 
#define ld          long double
#define pb          push_back
#define mp          make_pair
#define ff          first
#define se          second
#define endl        '\n'
#define fd(n)       fixed<<setprecision(n)
#define MAX         100000000000001
#define MAXN        400005
#define mod         1000000007 
using namespace std;
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n,m,mx,i,sum=0,x;
    cin>>n;
    ll a[n];
    for(i=0;i<n;i++){
        cin>>a[i];
    }
    x=a[0];
    sum++;
    for(i=1;i<n;i++){
        if(a[i]>=x){
            sum++;
            x=a[i];
        }
    }
    cout<<sum;
}