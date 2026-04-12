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
#define rep(i,n) for(i=0;i<(n);i++)
#define loop(i,a,n) for(i=a;i<(n);i++)
#define all(in) in.begin(),in.end()
#define shosu(x) fixed<<setprecision(x)

typedef vector<int> vi;
typedef vector<string> vs;
typedef pair<int,int> pii;

int main(void) {
    int i,j;
    int h,w;
    cin >> h >> w;
    vs s(h);
    rep(i,h) cin >> s[i];
    rep(i,h){
        rep(j,w)if(s[i][j] == '#')break;
        if(j == w){
            rep(j,w)s[i][j] = '*';
        }
    }
    rep(j,w){
        rep(i,h)if(s[i][j] == '#')break;
        if(i == h){
            rep(i,h)s[i][j] = '*';
        }
    }
    rep(i,h){
        bool t = false;
        rep(j,w)if(s[i][j]!='*')cout << s[i][j], t = true;
        if(t)cout << endl;
    }
}
