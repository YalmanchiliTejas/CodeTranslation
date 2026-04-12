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
    while(cin >> n, n){
        vp v;
        rep(i,n){
            int t;
            cin >> t;
            if(v.size()){
                if(v.back().first == t){
                    v.back().second++;
                }else if(i%2 == 0){
                    v.push_back(pii(t,1));
                }else{
                    int tmp = v.back().second + 1;
                    v.pop_back();
                    if(v.size())v.back().second += tmp;
                    else v.push_back(pii(t,tmp));
                }
            }else{
                v.push_back(pii(t,1));
            }
            //cout << "!"<<i << endl;
            //rep(j,v.size())cout << v[j].first << " " << v[j].second << endl;
        }
        int ans = 0;
        rep(i,v.size())if(!v[i].first)ans += v[i].second;
        cout << ans << endl;
    }
}

