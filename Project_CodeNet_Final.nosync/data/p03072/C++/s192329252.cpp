#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)cin >> a[i];
    int ret = 0;
    for (int i = 0; i < n; i++) {
        bool flag = true;
        for (int j = 0; j < i; j++) {
            if (a[i] < a[j])flag = false;
        }
        if (flag)ret++;
    }
    cout << ret << endl;
    return 0;
}