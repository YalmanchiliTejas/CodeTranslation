#include<bits/stdc++.h>
using namespace std;
 
#define rep(i, n) for (int i = 0; i < n; ++i)
#define all(x) (x).begin(),(x).end()
#define endl "\n"
 
using ll = long long;
using P = pair<int,int>;
using mp =  map<string,int>;
 
const int MOD = 1e9 + 7;
const int INF = 1001001001;
 
int main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
 
    int x, y, z;
    cin >> x >> y >> z;
 
    x -= z;
    x /= y+z;
    cout << x << endl;
 
    return 0;
}