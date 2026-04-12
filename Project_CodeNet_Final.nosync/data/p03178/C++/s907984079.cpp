#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <set>
#include <climits>
#include <queue>
#include <cstring>
#include <stack>
#include <map>
#include <ctime>
using namespace std;
#define rep(i,a,b) for(int i=a; i<=b; i++)
#define ii pair <int, int>
#define fi first
#define se second
#define ll long long
#define mod 1000000007
int d, f[10001][100][3];
string s;

int ss(int a, int b){
    if(a==b) return 1;
    if(a<b) return 0;
    return 2;
}

int tinh(){
    int n=s.size();
    rep(i,0,9) f[1][i%d][ss(i, s[0]-48)]++;
    rep(i,1,n-1) rep(r,0,d-1) rep(st,0,2) rep(x,0,9){
        if(f[i][r][st]==0) continue;
        (f[i+1][(r+x)%d][(st==1?ss(x, s[i]-48):st)]+=f[i][r][st])%=mod;
    }
    return (f[n][0][0] + f[n][0][1] - 1 + mod)%mod;
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
//	freopen("Test.inp", "r", stdin);
//    freopen("Test.out", "w", stdout);
    cin>>s>>d;
    cout<<tinh();
	return 0;
}
