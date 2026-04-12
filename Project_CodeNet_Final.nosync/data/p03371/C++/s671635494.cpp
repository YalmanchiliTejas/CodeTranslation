#include <bits/stdc++.h>
using namespace std;
const int INF = 1001001001;


int main() {
int A,B,C,X,Y;
cin >> A >> B >> C >> X >> Y;
int64_t ans1,ans2,ans3;
ans1 = A*X + B*Y;
ans2 = C * max(X,Y) *2;
if (X > Y) {
    ans3 = Y*2 * C;
    ans3 += A * (X-Y);
} else {
    ans3 = X*2 * C;
    ans3 += B * (Y-X);
}
cout << min(ans1,min(ans2,ans3)) << endl;

return 0;
}
