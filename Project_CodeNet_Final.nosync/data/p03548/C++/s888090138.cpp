#include <bits/stdc++.h>
#define rep(i,n) for(ll i=0;i<(n);++i)
#define all(a) (a).begin(),(a).end()
#define dunk(a) cout << (a) << endl
#define rall(a) (a).rbegin(),(a).rend()
const int INF = 2e9;
using namespace std;
using Graph = vector<vector<int>>;
typedef pair<int,int> P;
typedef long long ll;

int main(){
    int x,y,z;
    cin >> x >> y >> z;
    int r,ans;
   ans = 0;
    r = x - z;
    while (r>=y+z){
        ans++;
        r = r-y-z;
    }
    cout << ans << endl;
}