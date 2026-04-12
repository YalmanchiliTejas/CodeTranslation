#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
#include <utility>
#include <queue>
#include <set>
#include <map>
#include <deque>
#include <iomanip>
#include <cstdio>
#include <stack>

using namespace std;
typedef unsigned long long ll;
typedef pair<int,int> PII;
typedef vector<int> VI;
typedef vector<VI> VVI;
#define  MP make_pair
#define  PB push_back
#define inf  1000000007
#define rep(i,n) for(int i=0;i<(int)(n);++i)

vector<ll> a;
int main(){
    vector<ll> dp(100000);
    dp[0] = 1;
    int c = 0;
    ll k;
    cin >> k;
    vector<ll> cn(8);
    cn[0] = 1;
    for(int i=1;i<5000;i++){
        bool flag = 0;
        if(i%8!=0){
            dp[i] = cn[(i%8)-1];
            cn[(i%8)] += dp[i];
        }else{
            dp[i] = 1;
            cn[0]++;
        }
        if(i%8==7){
            if(dp[i]<(ll)1e18){    
                cerr << dp[i] << endl;
                a.PB(dp[i]);
                c++;
            }else{
                flag = 1;
                break;
            }
        }
        if(flag)break;
    }
    cerr << c << endl;
    vector<ll> cnt(c);
    for(int i=c-1;i>=0;i--){
        cnt[i] = k/a[i];
        k -= a[i]*cnt[i];
        cnt[i];
    }
    rep(i,c){
        cerr << a[i] << " " << cnt[i] << endl;
    }
    string ans;
    for(int i=c-1;i>=0;i--){
        for(int j=0;j<cnt[i];j++){
            ans += "F";
        }
        ans +="ESTIVAL";
    }

    cerr << ans.size() << endl;
    cout << ans << endl;
    
    return 0;
}