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
    int a,b,ab,x,y;
    cin >> a >> b >> ab >> x >> y;
    int ans = 0;
    if(x>y){
        swap(a,b);
        swap(x,y);
    }
    {
        int tmp = 0;
        tmp = a*x+b*y;
        ans = tmp;
    }
    {
        int tmp = 0;
        tmp = ab*x*2 + b*(y-x);
        ans = min(ans,tmp);
    }
    {
        int tmp = 0;
        tmp = ab*x*2 + ab*2*(y-x);
        ans = min(ans,tmp);
    }
    cout << ans << endl;
    return 0;
}