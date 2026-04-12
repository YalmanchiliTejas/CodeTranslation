#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cmath>
#include<cctype>
#include<math.h>
#include<string>
#include<string.h>
#include<stack>
#include<queue>
#include<vector>
#include<utility>
#include<set>
#include<map>
#include<stdlib.h>
#include<iomanip>

using namespace std;

#define ll long long
#define ld long double
#define EPS 0.0000000001
#define INF 1e9
#define MOD 1000000007
#define rep(i,n) for(int i=0;i<(n);i++)
#define loop(i,a,n) for(i=a;i<(n);i++)
#define all(in) in.begin(),in.end()
#define shosu(x) fixed<<setprecision(x)
#define int ll
typedef vector<int> vi;
typedef vector<string> vs;
typedef pair<int,int> pii;

int gcd(int a, int b){
    if(b==0) return a;
    return gcd(b,a%b);
}
int lcm(int a, int b){
    return a*b/gcd(a,b);
}

int sum[55] = {};
int p[55] = {};

int ans = 0;

void f(int n, int x){
    if(x <= 0)return;
    if(n == 0){
        ans++;
        return;
    }
    if(sum[n] <= x){
        ans += p[n];
        return;
    }
    x--;
    if(sum[n-1] <= x){
        ans += p[n-1];
        x -= sum[n-1];
        if(x>0)ans++;
        x--;
        f(n-1,x);
    }else{
        f(n-1,x);
    }

}

signed main(void) {
    int i,j;
    p[0] = sum[0] = 1;
    rep(i,50){
        sum[i+1] = 3 + 2 * sum[i];
        p[i+1] = 1 + 2 * p[i];
    }
    int n,x;
    cin >> n >> x;
    f(n,x);
    cout << ans << endl;
}
