#include <bits/stdc++.h>
using namespace std;
#define M_PI 3.14159265358979323846
#define MOD 1000000007
typedef long long ll;
typedef vector<int> vint;
typedef vector<vint> vvint;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef pair<int, int> ipair;
typedef pair<ll, ll> llpair;

/*
    Author: Koushik Sahu
    Created: 29 August 2020 Sat 17:43:13
*/

int n, a;
ll ans=0;

int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    cin>>n;
    ll prev = -1; 
    for(int i=0; i<n; i++){
        cin>>a;
        if(prev==-1){
            prev = a;
        }else{
            ans += ((prev*a)%MOD);
            ans %= MOD;
            prev += a;
            prev %= MOD;
        }
    }
    cout<<ans<<"\n";
    return 0;
}