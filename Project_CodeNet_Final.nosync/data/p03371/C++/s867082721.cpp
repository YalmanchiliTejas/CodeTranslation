#include <bits/stdc++.h>
using namespace std;
#define _GLIBCXX_DEBUG
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define REP(i, n) for (int i = 1; i < (int)(n); i++)
#define Sort(a) sort(a.begin(), a.end())
typedef long long int ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vll;
template <class T> inline bool chmax(T& a,T b){if(a<b){a=b;return true;} return false;}
template <class T> inline bool chmin(T& a,T b){if(a>b){a=b;return true;} return false;}

int main(){
    int a, b, c, x, y;
    cin >> a >> b >> c >> x >> y;
    ll sum = 0;
    if(a+b > 2*c){
        sum += 2*c*min(x, y);
        int tmp = min(x, y);
        x = x - tmp;
        y = y - tmp;
        if(max(x*a, y*b) > 2*c*max(x, y)){
            sum += 2*c*max(x, y);
            x = 0;
            y = 0;
        }
    }
    sum += x*a + y*b;
    cout << sum << endl;
    return 0;
}