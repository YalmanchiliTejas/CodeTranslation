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
#include <map>
using namespace std;
//cout <<  << endl;
typedef long long int ll;
typedef long double ld;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const ll INF = 1LL << 60;
#define MOD 1000000007
#define MAX_V 100010
#define MAX_N 1000100
bool x[MAX_N];
ll num[MAX_N];
ll fibl[MAX_N]={0};
 
ll fib(ll a){
    if (fibl[a]!=0)return fibl[a];
    if (a==0){
        return 0;
    }else if (a==1){
        return 1;
    }
    return fibl[a]=fib(a-1)+fib(a-2);
}
 
ll eratosthenes(ll n) {
    int p = 0;
    for (ll i=0; i<=n; ++i) x[i] = true;
    x[0] = x[1] = false;
    for(int i=2; i<=n; ++i) {
        if(x[i]) {
            p++;
            for(int j=2*i; j<=n; j+=i) x[j] = false;
        }
        
        num[i] = p;
    }
    return p;
}
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

map<ll,ll> prime_factor(ll n){
    map<ll,ll> mp;
    for(ll i=2; i*i<=n; i++){
        while(n % i == 0){
            mp[i]++;
            n /= i;
        }
    }
    if(n != 1) mp[n] = 1;
    return mp;
}

ll keta(ll N){
    int tmp{};
    while( N > 0 ){
        tmp += ( N % 10 );
        N /= 10;
    }
    N = tmp;
    return N;
}

int main(){
    char s;
    cin >> s;
    if (s=='a' || s=='i'|| s=='u'|| s=='e'|| s=='o'){
        cout << "vowel" << endl;
    }else{
        cout << "consonant" << endl;
    }
    return 0;
}

