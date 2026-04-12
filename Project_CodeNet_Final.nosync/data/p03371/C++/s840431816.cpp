#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<bool> vb;
typedef vector<char> vc;
typedef vector<ll> vll;
typedef vector<vector<int>> vvi;
typedef vector<vector<string>> vvs;
typedef vector<vector<char>> vvc;
typedef vector<vector<bool>> vvb;
typedef pair<int,int> P;
typedef pair<ll, ll> Pll;
#define vrep(v,n) for(int i=0;i<n;i++){cin >> v.at(i);} 
#define rep(i, l, n) for (int i = l; i < (int)(n); i++)
#define repn(i, l, n) for (int i = l; i <= (int)(n); i++)
#define pb push_back 
#define sort(v) sort(v.begin(), v.end())
#define sortr(v) sort(v.rbegin(), v.rend())
void chmin(int &a, int b) {if(a > b) a = b;}
void chmax(int &a, int b) {if(a < b) a = b;}

const int mod = 1000000007;
const int inf = 1e9;
#define PI 3.14159265369;
int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};


int main(){
    ll a, b, c, x, y;
    cin >> a >> b >> c >> x >> y;
    ll ans = 1e10;
    for(int i = 0 ; i <= max(x,y)*2 ; i+=2){
        ll k = max((ll)0, x-i/2)* a + max((ll)0, y-i/2)*b+i*c;
        ans = min(ans, k);
    }

    cout << ans;
}