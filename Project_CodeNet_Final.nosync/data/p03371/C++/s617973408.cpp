#include<bits/stdc++.h>
using namespace std;
using Graph = vector<vector<int>>;
#define rep(i,n) for(int i=0;i<n;++i)
#define all(v) v.begin(), v.end()
#define PI 3.141592653589793238462643383279
typedef long long int ll;
typedef unsigned long long ull;
template<class T> inline bool chmin(T& a, T b) {if (a > b) {a = b;return true;}return false;}
template<class T> inline bool chmax(T& a, T b) {if (a < b) {a = b;return true;}return false;}
typedef pair<ll,ll> P;
const long long MOD = 1e9+7;
const ll INF = 1LL << 60;

int main(){
    int a,b,c,x,y;
    cin >> a >> b >> c >> x >> y;
    int ans = 0;
    if(2 * c < a + b){
        ans += min(x,y)*2*c;

        if(x > y){
            if(a < 2*c){
                ans += (x-y)*a;
            }else{
                ans += (x-y)*2*c;
            }

        }else{
            if(b < 2*c){
                ans += (y-x)*b;
            }else{
                ans += (y-x)*2*c;
            }

        }

    }else{
        ans += x*a+y*b;
    }

    cout << ans << endl;

}