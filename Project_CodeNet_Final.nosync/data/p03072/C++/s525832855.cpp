/**
 *   author: bholuakku
**/

#include <bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define X first
#define Y second
#define MOD 1000000007
#define Endl cout<<"\n"
#define Test cout<<"Hello\n"

using namespace std;

typedef long long ll;

int power(ll x, ll y, ll p) { ll res = 1; x = x % p; while (y>0){ if (y & 1) res = (res*x) % p; y = y>>1; x = (x*x)%p;} return res;}
int modInverse(ll n) {ll p = MOD;return power(n, p-2, p);}
int min(int a, int b, int c) { return min(a, min(b, c)); }
int max(int a, int b, int c) { return max(a, max(b, c)); }
inline void swap(int &a, int &b) { int t = a; a = b; b = t;}
bool cmp(int a, int b){return a>b;}

vector<bool> sieve;
vector<int> ans(3000000);

void fill(){
    sieve.assign(3000010, true);
    for(int i = 2; i*i<=3000000; i++){
        if(sieve[i]){
        for(int j = i*i; j<=3000000; j+=i){
            sieve[j] = false;
        }
        }
    }
    ans[1] = 0;
    for(int i = 2; i<2100000; i++){
        ans[i] = ans[i-1];
        if(sieve[i]) ans[i]++;
    }
}

int main(){
    int n, ans=1;
    cin>>n; int mount[n];
    for(auto &m : mount) cin>>m;
    int curr = mount[0];
    for(int i = 1; i<n; i++) if(mount[i]>=curr) curr = mount[i], ans++;
    cout<<ans;
    return 0;
}
