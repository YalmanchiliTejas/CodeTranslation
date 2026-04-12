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
#include<complex>

using namespace std;

#define ll long long
#define ld long double
#define EPS 1e-9
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
typedef vector<vi> vvi;

int gcd(int a, int b){if(b==0) return a;return gcd(b,a%b);}
int lcm(int a, int b){return a/gcd(a,b)*b;}


signed main(void) {
    int n;
    cin >> n;
    vi a(n);
    rep(i,n) cin >> a[i];
    map<int,int> ma;
    rep(i,n){
        auto itr = ma.upper_bound(-a[i]);
        if(itr != ma.end()){
            int num = itr->first;
            //cout << (itr->first) << " " << (itr->second) << endl;
            ma[num]--;
            if(ma[num] == 0){
                ma.erase(num);
            }
        }
        ma[-a[i]]++;
    }
    int ans = 0;
    for(auto x: ma){
        ans += x.second;
    }
    cout << ans << endl;
}
