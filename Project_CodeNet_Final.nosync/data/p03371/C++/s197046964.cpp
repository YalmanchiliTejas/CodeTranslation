#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main(){
	int a, b, c, x, y;
    cin >> a >> b >> c >> x >> y;
    int cos = a*x + b*y;
    int min = cos;
    int cco = 0;
    int k = max(x, y);
    while(!(x == 0 && y == 0)){
      if(x > 0) x--;
      if(y > 0) y--;
      cco += 2;
      cos = a*x + b*y +c*cco;
      if(cos < min) min = cos;
    }
	cout << min << endl;
    return 0;
}