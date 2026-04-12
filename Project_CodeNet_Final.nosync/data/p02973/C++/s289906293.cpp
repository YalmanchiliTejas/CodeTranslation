#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <cmath>
#include <cstring>
#include <iomanip>
#include <random>
#include <chrono>
#include <queue>
#include <math.h>
#include <string>
#include <sstream>
#include <stack>
#include <deque>
#define inf 1e9+7
#define pb push_back
#define make make_pair
#define kaku(a) cout << a << endl;
 
using namespace std;
 
#define ll long long
#define rep(i,n) for(ll i=0;i<n;i++)
#define PI 3.14159265359
long long gcd(long long a,long long b){ return b==0?a:gcd(b,a%b);}
long long lcm(long long a,long long b){ return a/gcd(a,b)*b;}
 
typedef pair<ll,ll> Pair;
const ll MAX_L=10000;
 

int main(){
    ll n;
    cin >> n;
    deque<ll> q;
    ll a;
    cin >> a;
    q.pb(a);
    for(ll i=1;i<n;i++){
        cin >> a;
        auto itr=lower_bound(q.begin(),q.end(),a);
        if(itr==q.end()){
            if(q.back()<a) q.back()=a;
            else q.pb(a);
        }
        else{
            if(itr==q.begin()) q.push_front(a);
            else *(itr-1)=a;
        }
    }
    kaku(q.size());
}

