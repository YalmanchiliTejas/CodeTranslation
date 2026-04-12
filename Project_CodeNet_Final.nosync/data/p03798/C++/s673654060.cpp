//#include <bits/stdc++.h>
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <string>
#include <vector>
#include <map>
#include <queue>

using namespace std;

typedef long long ll;
typedef vector<int> vint;
typedef vector<vector<int> > vvint;
typedef vector<long long> vll, vLL;
typedef vector<vector<long long> > vvll, vvLL;
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n) for(int i=0;i<n;++i)
#define mod (ll)(1e9+7)
#define FIX(a) ((a)%mod+mod)%mod
#define ALL(obj) (obj).begin(), (obj).end()
#define rALL(obj) (obj).rbegin(), (obj).rend()
#define INF 1000000000 //1e9
#define LLINF 2000000000000000000LL //2e18
#define fi first
#define se second
#define pb push_back
int dy[]={0, 0, 1, -1};
int dx[]={1, -1, 0, 0};

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll n;
    cin >> n;
    string s;
    cin >> s;
    REP(x,4){
        vint a(n);
        a[0] = (x&1);
        a[1] = ((x>>1)&1);
        for(ll i=1;i<n-1;++i){
            if(a[i]==0){
                if(s[i]=='o'){
                    a[i+1] = a[i-1];
                }else{
                    a[i+1] = 1-a[i-1];
                }
            }else{
                if(s[i]=='o'){
                    a[i+1] = 1-a[i-1];
                }else{
                    a[i+1] = a[i-1];
                }
            }
        }
        if((a[0]==0&&s[0]=='o')||(a[0]==1&&s[0]=='x')){
            if(a[1]!=a[n-1]) continue;
        }
        if((a[0]==0&&s[0]=='x')||(a[0]==1&&s[0]=='o')){
            if(a[1]==a[n-1]) continue;
        }
        if((a[n-1]==0&&s[n-1]=='o')||(a[n-1]==1&&s[n-1]=='x')){
            if(a[0]!=a[n-2]) continue;
        }
        if((a[n-1]==0&&s[n-1]=='x')||(a[n-1]==1&&s[n-1]=='o')){
            if(a[0]==a[n-2]) continue;
        }
        string sw = "SW";
        REP(i,n){
            cout << sw[a[i]];
        }
        cout << endl;
        return 0;
    }
    cout << -1 << endl;
    return 0;
}