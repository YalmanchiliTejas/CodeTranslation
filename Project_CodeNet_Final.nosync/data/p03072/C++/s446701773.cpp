#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <math.h>
#include <iomanip>
#include <bitset>
#include <string>
#include <cstring>
#include <stdlib.h>
#include <utility>
#include <set>
using namespace std;
//cout <<  << endl;
typedef long long int ll;
typedef long double ld;
const ll INF = 1LL << 60;
#define MOD 1000000007
#define MAX_V 100010
#define MAX_N 100010

bool pairCompare(const pair<double,ll>& firstElof, const pair<double,ll>& secondElof){
    return firstElof.second < secondElof.second;
}

ll gcd(ll a,ll b){
    if (a%b==0)return(b);
    else return(gcd(b,a%b));
}

ll junnretu(ll n){
    ll ans=1;
    for (ll i=1;i<=n;i++){
        ans*=i;
    }
    return ans;
}

int main(){
    ll n,max=0,ans=0;
    cin >> n;
    
    for (ll i=0;i<n;i++){
        ll x;
        cin >> x;
        if (x>=max){
            ans++;
            max=x;
        }
    }
    cout << ans << endl;
    return 0;
}