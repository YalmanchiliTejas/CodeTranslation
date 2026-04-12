#include <bits/stdc++.h>
#include <string>
using namespace std;


int main(){
    int64_t n, total = 0, a, t = pow(10, 9) + 7, ans = 0;
    cin >> n;
    vector<int64_t> vec(n);
    for(int i = 0; i < n; i++) {
        cin >> vec.at(i);
        total += vec.at(i);
    }

    for (int i = 0; i < n - 1; i++){
        total -= vec.at(i);
        a = total % t;
        ans += vec.at(i) * a;
        ans = ans % t;
    }

    cout << ans << endl;

}