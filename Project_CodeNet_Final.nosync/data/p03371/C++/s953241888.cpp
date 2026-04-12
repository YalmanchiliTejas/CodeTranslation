#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
    int a, b, c, x, y, n, ans = 0, cnt = 0;
    cin >> a >> b >> c >> x >> y;
    n = 2*max(x, y);
    ans = a*x+b*y;
    for(int i=2;i <= n;i+=2){
      cnt = max(0, a*(x-i/2)) + max(0, b*(y-i/2)) + c*i;
      if(cnt < ans){
        ans = cnt;
      }
    }

    cout << ans << endl;
}
