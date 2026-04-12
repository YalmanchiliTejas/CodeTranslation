//#include <fsociety>
#include <cmath>
#include <deque>
#include <algorithm>
#include <iterator>
#include <list>
#include <map>
#include <unordered_map>
#include <queue>
#include <set>
#include <unordered_set>
#include <stack>
#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include <iomanip> 
#include <stdio.h>
//end of libraries ;
// freopen("input.txt","r",stdin);
// freopen("output.txt","w",stdout);
// ll lmax(ll o , ll w) {if(o>w)return o; return w;}
// ll lmin(ll o , ll w) {if(o<w)return o; return w;}
#define LNF 3999999999999999999
#define INF 999999999
#define N 3000003
#define PI 3.14159265359
#define endl "\n"
#define F first
#define S second
#define pb push_back
#define ll long long
#define all(c) (c).begin(),(c).end()
#define sz(c) (ll)(c).size()
#define mkp(a,b) make_pair(a,b)
#define fcin ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0);
using namespace std;
ll n , a[N] , sum , ans , mod = 1e9 + 7;
int main(){
fcin;
    cin >> n;
    for(ll i = 0 ; i < n ; i++) cin >> a[i] , sum += a[i];
    for(ll i = 0 ; i < n ; i++){
        sum -= a[i];
        a[i] %= mod;
        ans += (sum + mod )%mod * a[i];
        ans%=mod;
    }
    cout << ans << "\n";
}