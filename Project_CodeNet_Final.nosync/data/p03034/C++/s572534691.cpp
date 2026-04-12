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
#define LINF (ll)INF*INF
#define MOD 1000000007
#define rep(i,n) for(int i=0;i<(n);i++)
#define loop(i,a,n) for(int i=a;i<(n);i++)
#define all(in) in.begin(),in.end()
#define shosu(x) fixed<<setprecision(x)

#define int ll //!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

typedef vector<int> vi;
typedef vector<string> vs;
typedef pair<int,int> pii;
typedef vector<pii> vp;

int gcd(int a, int b){
    if(b==0) return a;
    return gcd(b,a%b);
}
int lcm(int a, int b){
    return a/gcd(a,b)*b;
}


signed main(void) {
    int n;
    cin >> n;
    vi s(n);
    rep(i,n)cin >> s[i];
    int ans = 0;
    loop(c,1,n-1){//t = f(k,c)を求める
        int t = 0;
        int ma = -INF;
        map<int,int> mp;
        //cout << "c=" << c << endl;
        for(int k = 0; c*k < n-1; k++){
            if(mp[n-1-k*c] || mp[k*c] || n-1-k*c == k*c || n-1-k*c < c)break;
            //printf("(%lld, %lld) ",n-1-k*c,k*c);
            mp[n-1-k*c]++;
            mp[k*c]++;
            t += s[n-1-k*c] + s[k*c];
            ma = max(ma, t);
        }
        //cout << endl;
        //cout << "ma:" << ma << endl;
        ans = max(ans, ma);
    }
    cout << ans << endl;
}
