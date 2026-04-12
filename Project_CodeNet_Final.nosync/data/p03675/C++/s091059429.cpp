#include <bits/stdc++.h>

using namespace std;

int n;

vector<int> arr;

vector<int> res;

int main() {
    cin >> n;

    int num;
    for(int i = 0; i < n; i++) {
        cin >> num;
        arr.push_back(num);
    }

    res.resize(n);
    
    int l_p = 0, r_p = n-1;
    
    for(int i = n-1, c = 0; i >= 0; i--, c++) {
        if (c % 2 == 0) {
            // left
            res[l_p++] = arr[i];
        } else {
            res[r_p--] = arr[i];
        }
    }

    for(int i = 0; i < n; i++) {
        if (i) {
            cout << " ";
        }
        cout << res[i];
    }

    cout << endl;
    
    return 0;
}
