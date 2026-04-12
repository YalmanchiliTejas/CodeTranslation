//@author :  |< U $ |-|
#include<cmath>
#include<iostream>
#include<vector>
#include<set>
#include<map>
#include<stack>
#include<deque>
#include<queue>
#include<algorithm>
#include<list>
#include<cstring>
#include<unordered_map>
#define ll long long
// #define pb push_back
// #define pop pop_back
#define in(i,n) for(i=0;i<n;i++)
#define pi pair<long long ,long long>
#define mp make_pair
#define F first
#define S second
#define all(v) v.begin(),v.end()
#define jaldi ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define inm1(b)  memset(b,-1,sizeof(b))
#define in0(b) memset(b,0,sizeof(b))
#define ininf(b) memset(b,1000000001,sizeof(b))

#define inf 10000000001
#define d1(a) cout<<a<<" "<<endl
#define d2(a,b) cout<<a<<" "<<b<<endl
#define d3(a,b,c) cout<<a<<" "<<b<<" "<<c<<endl
#define TakeInput freopen("input.txt", "r", stdin);freopen("output.txt", "w", stdout);
using namespace std;
ll MOD = 1e9+7;
int main(){
    jaldi
    #ifndef ONLINE_JUDGE
    TakeInput
    #endif

    ll i,j,k,n,m;
    ll t;
    
    cin>>n;
    ll a[n];
    ll suf[n];

    for(i=0;i<n;i++){
        cin>>a[i];
    }
    suf[n-1] = a[n-1];
    for(i=n-2;i>=0;i--){
        suf[i] = suf[i+1]+a[i];
    }
    ll sum = 0; 
    for(i=0;i<n-1;i++)
    {
        sum += ((a[i]%MOD)*(suf[i+1]%MOD))%MOD;
        sum%=MOD;
    }

    d1(sum);
    
}
