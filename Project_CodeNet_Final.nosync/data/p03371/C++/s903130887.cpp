#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
#define rrep(i, n) for (int i = n - 1; i >= 0; i--)
using namespace std;
using Graph = vector<vector<int>>;
typedef long long ll;
typedef pair<int,int> P;

int main(){
    int a, b, c, x, y;
    cin >> a >> b >> c >> x >> y;
    int ans1 = a * x + b * y;
    int ans2;
    if (x >= y){
        ans2 = min(a * (x - y) + 2 * c * y, 2 * c * x); 
    }
    else {
        ans2 = min(2 * c * x + b * (y - x), 2 * c * y); 
    }
    cout << min(ans1, ans2) << endl;
    return 0;
}