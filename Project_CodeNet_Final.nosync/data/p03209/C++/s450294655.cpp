#include <iostream>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <algorithm>
#include <string>
#include <array>

using namespace std;

// 厚さ
vector<long long> b(51, 0);
// パティの枚数
vector<long long> p(51, 0);

long long barger(int k){
    if(k == 0){
        b[0] = 1;
        return 1;
    }
    else {
        b[k] = 3 + 2 * barger(k-1);
        return b[k];
    }
}

long long patti(int k){
    if(k == 0){
        p[0] = 1;
        return 1;
    }
    else {
        p[k] = 1 + 2 * patti(k-1);
        return p[k];
    }
}

int main()
{
    long long n, x, key;
    cin >> n >> x;
    key = x - 1;
    long long max = barger(n);
    long long ans = patti(n);
    long long mid = 0;
    long long left = 0;
    long long right = max - 1;
    ans = p[n];
    /* debug
    for (int i=0; i<=4; ++i){
        cout << i << ": patty:" << p[i] << " @ barger:" << b[i] << endl;
    }
    */
    // find
    // cout << "key -> " << key << endl;
    for (int i=n; i>=0; --i){
        mid = (left + right) / 2;
        // cout << i << ":[" << left << ", " << mid << ", " << right << ")" << " ans -> " << ans << " ";
        if(key == mid){
            // cout << "mid" << endl;
            ans -= (i > 0) ? p[i-1] : 0;
            break;
        }
        else if(key < mid){
            // cout << "down" << endl;
            left++;
            right = mid - 1;
            ans -= (i > 0) ? (p[i-1] + 1) : 1;
        }
        else {
            // cout << "up" << endl;
            left = mid + 1;
            right--;
        }
    }
    cout << ans << endl;
}
