#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef pair<int,int> P;
 
const int INF = 1e9;
const int mod = 1e9+7;

int main()
{
    int a,b,c,x,y;
    cin >> a >> b >> c >> x >> y;

    vector<ll> ans(3);
    ans[0] = a * x + b * y;
    ans[1] = 2 * c * max(x,y);
    ans[2] = 2 * c * min(x,y);
    if(x > y) ans[2] += a * (x - y);
    else if(x < y) ans[2] += b * (y - x);
    
    cout << *min_element(ans.begin(),ans.end()) << endl;

    return 0;
}