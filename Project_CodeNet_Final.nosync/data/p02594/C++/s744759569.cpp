#include <bits/stdc++.h>
#include <map>
#include <algorithm>
#include <vector>
#include <string.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <chrono>
#include <thread>
#include <string.h>
 
#define rep(i,n)    for(ll i=0;i<n;i++)
#define repu(i,k,n) for(int i=k;i<=n;i++)
#define repd(i,k,n) for(ll i=k;i>=n;i--)
#define se second
#define fi first
#define pb push_back
#define mp make_pair
#define mt make_tuple
#define endl "\n"
#define INF (ll)ll_MAX
 
typedef long long ll;
typedef long double ld;
typedef std::pair<ll, ll> pii;
typedef std::vector< ll > vi;
typedef std::vector< pii > vii;
typedef std::vector< ll > vll;
typedef std::vector< std::pair < pii, ll > > vpp;
 
const ll N = 3*1e5 +5 ;
const long long MOD = 1000000007;
const long long MOD2 = 998244353;
const long long inf = 1e18;
 
using namespace std;

ll g[200000], ig[200000];

bool istrue(int perm[], int n){
    map <int,int> mm;
    for(int i=1;i<=n;i++){
        mm[i+perm[i]]++;
        if(mm[i+perm[i]]>1) return 0;
    }

    map <int,int> mm2;
    for(int i=1;i<=n;i++){
        mm2[i-perm[i]]++;
        if(mm2[i-perm[i]]>1) return 0;
    }

    return 1;
}

void findall(vector<string> &ans, string ptup, int left, int right, int n){
    
    if(ptup.size()==2*n){
        ans.push_back(ptup);
        // cout<<"yo";
        return;
    }
    if(left){
        ptup+='(';
        findall(ans,ptup,left-1,right,n);
        ptup.pop_back();
    }
    if(left!=right and right){
        ptup+=')';
        findall(ans,ptup,left,right-1,n);
        ptup.pop_back();        
    }
    
}


void solve()
{   

    int x;
    cin>>x;

    if(x>=30) cout<<"Yes\n";
    else cout<<"No";



}

int main() {

    g[1] = 1;
    ig[1] = 1;
    for (ll i = 2; i < 100000; ++i) {
        g[i] = 1 + g[i - g[g[i - 1]]];
        ig[i] = ig[i - 1] + i * g[i];
    }


    // #ifndef ONLINE_JUDGE
    //     // for getting input from input.txt
    //     freopen("input.txt", "r", stdin);
    //     // for writing output to output.txt
    //     freopen("output.txt", "w", stdout);
    // #endif


    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    ll t = 1;
    // cin>>t;
    ll ctr=0;
    while(t--)
    {   
        ctr++;
        // cout<<"Case #"<<ctr<<": ";
        solve();    
    } 
    cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC << "ms\n";
 
}