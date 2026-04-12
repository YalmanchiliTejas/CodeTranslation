    #include <bits/stdc++.h>
    using namespace std;
     
    int main() {
      int a, b, c, x, y, maxpizza, ans;
      cin >> a >> b >> c >> x >> y;
      int max1 = max(x, y);
      int min1 = min(x, y);
      if (max1 == x) maxpizza = a;
      else maxpizza = b;
      
      if (2 * c <= a + b && (max1 - min1) * maxpizza <= 2 * c * (max1 - min1)) ans = 2 * c * min1 + (max1 - min1) * maxpizza;
      else if (2 * c <= a + b && (max1 - min1) * maxpizza > 2 * c * (max1 - min1)) ans = 2 * c * max1;
      else ans = a * x + b * y;
      cout << ans << endl;
    }