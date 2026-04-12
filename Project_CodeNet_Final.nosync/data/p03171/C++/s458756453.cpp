/**
 *   author: malviyanshiv
 *   created: 09 January 2019  23:27:27
**/

#include <bits/stdc++.h>

using namespace std;

#define REP(i, a, b) for(int i = a; i < b; i++)
#define RREP(i, a, b) for(int i = a-1; i >= b; i--)
#define PB push_back
#define MP make_pair
#define MOD 1000000007
#define INF 0x7fffffff
#define MAX 3001

typedef long long ll;
typedef pair< int, int > PII;

void fastscan(int &x){
    bool neg=false;
    register int c;
    x =0;
    c=getchar();
    if(c=='-'){
        neg = true;
        c=getchar();
    }
    for(;(c>47 && c<58);c=getchar())
        x = (x<<1) + (x<<3) +c -48;
    if(neg)
        x *=-1;
}

void optimizeIO(){
	ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
}

vector< vector<ll> > dp(MAX, vector<ll>(MAX));
vector< vector<bool> > vis(MAX, vector<bool>(MAX, false));
vector<ll> inp(MAX);

ll cal(int l, int r, int turn){
    if( l > r )
        return 0;
    if( vis[l][r] )
        return dp[l][r];

    if( turn ){
        vis[l][r] = true;
        return dp[l][r] = min( cal(l+1, r, 1-turn)-inp[l], cal(l, r-1, 1-turn)-inp[r]);
    }else{
        vis[l][r] = true;
        return dp[l][r] = max( cal(l+1, r, 1-turn)+inp[l], cal(l, r-1, 1-turn)+inp[r]);
    }
    
}

int main(){
	optimizeIO();
    
    int n;
    cin >> n;
    REP(i, 0, n)
        cin >> inp[i];

    cout << cal(0, n-1, 0) << endl;

	return 0;
}