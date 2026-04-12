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

    int h,w;
    cin >> h >> w;
    vs s(h);
    rep(i,h)cin >> s[i];
    vi t(4,INF);
    int v[4][2] = {{-1,-1},{-1,w},{h,-1},{h,w}};
    rep(i,h)rep(j,w)if(s[i][j] == 'B'){
        rep(x,4){
            t[x] = min(t[x], abs(v[x][0]-i)+abs(v[x][1]-j));
        }
    }
    vp p;
    rep(i,h)rep(j,w)if(s[i][j] == 'B'){
        rep(x,4){
            if(abs(v[x][0]-i)+abs(v[x][1]-j) == t[x]){
                p.push_back(pii(i,j));
            }
        }
    }
    int ans = 0;
    rep(i,p.size())rep(j,i){
        ans = max(ans, abs(p[i].first - p[j].first)+abs(p[i].second - p[j].second));
    }
    cout << ans << endl;
}

