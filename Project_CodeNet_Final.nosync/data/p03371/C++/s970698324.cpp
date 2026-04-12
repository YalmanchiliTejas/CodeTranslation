#include<bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < n; ++i)
#define all(x) (x).begin(),(x).end()
#define endl "\n"

using ll = long long;
using P = pair<int,int>;
using mp =  map<char,int>;

const int MOD = 1e9 + 7;
const int INF = 1001001001;


int main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

    int a, b, c, x, y;
    cin >> a >> b >> c >> x >> y;

    int A = 0, B = 0, C = 0;
    if(x > y){
        A = y * c * 2 + (x - y) * a;
    }else{
        A = x * c * 2 + (y - x) * b;
    }

    B = max(x, y) * c * 2;
    C = a * x + b * y;

    int ans = min(A, min(B, C));
    cout << ans << endl;


    return 0;
}