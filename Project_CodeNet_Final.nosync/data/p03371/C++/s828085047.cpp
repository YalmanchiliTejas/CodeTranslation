#include <bits/stdc++.h>
#define MOD (long long)(1E9+7)
#define rep(i, n) for(int i = 0; i < n; i++)

using namespace std;

int main(){
	int a,b,c,x,y, tmp;
	cin >> a >> b >> c >> x >> y;
	int ans = a * x + b * y;	
    for(int i = 1; i <= max(x, y); i++) {
      //2iがABピザの枚数
     	tmp = 2 * i * c;
      	tmp += max(0, a * (x-i)) + max(0, b * (y - i));
		ans = min(ans, tmp);
    }
	cout << ans << endl;
}