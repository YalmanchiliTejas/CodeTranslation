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
int a[3001];
ll f[3002][3002];
ll s[3002];

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
//	freopen("Test.inp", "r", stdin);
//    freopen("Test.out", "w", stdout);
    int n;
    cin>>n;
    rep(i,1,n) cin>>a[i];
    rep(i,1,n) f[i][i]=a[i];
    rep(i,1,n) s[i]=a[i]+s[i-1];
    for(int i=n-1;i;i--){
        rep(j,i+1,n){
            f[i][j]=s[j]-s[i-1]-min(f[i+1][j], f[i][j-1]);
        }
    }
//    rep(i,1,n){
//        rep(j,1,n) cout<<f[i][j]<<' ';
//        cout<<endl;
//    }
    cout<<2ll*f[1][n]-s[n];
	return 0;
}
