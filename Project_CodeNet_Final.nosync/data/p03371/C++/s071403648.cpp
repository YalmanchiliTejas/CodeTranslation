#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
    int A, B, C, X, Y;
    cin >> A >> B >> C >> X >> Y;

    int ans;
    if (A + B <= 2 * C)
    {
        cout << A * X + B * Y << endl;
        return 0;
    } else
    {
        int temp1, temp2;
        temp1 = 2 * C * min(X, Y);
        if (X > Y)
        {
            temp1 += (A * (X - Y));
        } else
        {
            temp1 += (B * (Y - X));
        }
        temp2 = 2 * C * max(X, Y);
        ans = min(temp1, temp2);
    }
    cout << ans << endl;
    
    
  return 0;
}