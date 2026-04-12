    #include <bits/stdc++.h>
    using namespace std;
     
    int main() {
        cin.tie(nullptr);
        ios::sync_with_stdio(false);
     
        long a, b, c, x, y;
        cin >> a >> b >> c >> x >> y;
     
        long min_num = min(x, y);
        long sum = 0;
        if (a + b < c * 2) {
            sum += (a + b) * min_num;
        } else {
            sum += c * 2 * min_num;
        }
     
        if (x > y) {
            if (a < c * 2) {
                sum += a * (x - min_num);
            } else {
                sum += c * 2 * (x - min_num);
            }
        } else {
            if (b < c * 2) {
                sum += b * (y - min_num);
            } else {
                sum += c * 2 * (y - min_num);
            }
        }
     
     
        cout << sum << '\n';
     
        return 0;
    }