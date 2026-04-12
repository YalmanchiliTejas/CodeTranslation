#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <string>
#include <cmath>
#include <set>
#include <stack>
#include <queue>
#include <numeric>
#include <deque>
#include <cstring>
#include <iterator>
#include <map>
#include <cstdlib>
#include <unordered_map>
#include <unordered_set>
#include <iomanip>
#include <complex>
#include <bitset>
#include <chrono>
#include <random>
#include <assert.h>
#include <array>

using namespace std;

#define pb push_back
#define fi first
#define se second
#define all(x) (x).begin(),(x).end()
#define mn(x) *min_element((x).begin(),(x).end())
#define mx(x) *max_element((x).begin(),(x).end())
//#define sum(x) accumulate((x).begin(),(x).end(),0ll)
#define eb emplace_back
#define el '\n'
typedef  long long  ll;
typedef  unsigned long long  ull;
typedef long double ld;
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;
typedef vector<ll> vll;
typedef vector<int> vi;
typedef vector<pii> vpi;
typedef vector<pll> vpll;
typedef vector<vi> vvi;
typedef vector<vll> vvll;
typedef vector<bool> vb;
typedef vector<string> vs;

const ld pi=acos(-1);
const ll inf=(ll)1e9+1;
const int mod=1000000007;
//const int mod=998244353;

int n,m,k;
const int N=1e3+10;





int main()
{   ios_base::sync_with_stdio(false);cin.tie(NULL);
    int q,t,u,v,h;
    ll x,a,b,c,d,y,z;
    cin >> n;
    vll vv(n+1), sm(n+1);
    for(int i=1; i<=n; i++){
        cin >> vv[i];
        sm[i]=vv[i]+sm[i-1];
        sm[i]%=mod;
    }
    a=0;
    for(int i=1; i<n; i++){
        a+=vv[i]*(sm[n]-sm[i]+mod);
        a%=mod;
    }
    cout << a << el;
    
    return 0;
}





