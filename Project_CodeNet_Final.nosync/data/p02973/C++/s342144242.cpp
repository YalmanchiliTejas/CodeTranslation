#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <queue>
#include <iomanip>
using namespace std;
typedef long long ll;

int main() {
    int n, a[100010];
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];

    vector<int> ans;
    ans.push_back(2000000000);
    for (int i = 0; i < n; i++) {
        if (ans[ans.size() - 1] >= a[i]) {
            ans.push_back(a[i]);
        }
        else {
            int l = 0, r = ans.size();
            while (r - l > 1) {
                int mid = (l + r) / 2;
                if (ans[mid] >= a[i]) l = mid;
                else r = mid;
            }
            ans[r] = a[i];
           // cout << i << " " << ans[l] << endl;
        }
        /*cout << "y ";
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " " ;
        }
        cout << endl;*/
    }

    cout << ans.size() - 1 << endl;
}

/*
g++ -std=c++14 abc134/e.cpp
 */