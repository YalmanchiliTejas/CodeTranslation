#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef long double ld;

// ■■■■■■■■■■■■■■■■headerここまで■■■■■■■■■■■■■■■■

int main(void) {

    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    vector<int> arr(n);
    int length = 0;

    arr[0] = a[0];

    for (int i = 1; i < n; i++) {
        if (arr[length] >= a[i]) {
            length++;
            arr[length] = a[i];
        }
        else {
            for (int j = 0; j <= length; j++) {
                if (arr[j] < a[i]) {
                    arr[j] = a[i];
                    break;
                }
            }
        }
    }
    cout << length + 1 << endl;
    return 0;

}
