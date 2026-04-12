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
    int h,w;
    cin >> h >> w;
    int now = 0;
    vector<string> s(h);
    REP(i,h) cin >> s[i];
    REP(i,h){
        int next = -1;
        REP(j,w){
            if(j<now){
                if(s[i][j]=='#'){
                    puts("Impossible");
                    return 0;
                }
            }else{
                if(next==-1||next==j-1){
                    if(s[i][j]=='#'){
                        next = j;
                    }
                }else{
                    if(s[i][j]=='#'){
                        puts("Impossible");
                        return 0;
                    }
                }
            }
        }
        now = next;
    }
    puts("Possible");
    return 0;
    return 0;
}