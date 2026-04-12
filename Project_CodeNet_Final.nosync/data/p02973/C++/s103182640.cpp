#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {
    int N; cin >> N;
    vector<int> a(N);
    for (int i = 0; i < N; i++) cin >> a[i];

    vector<int> b(1);
    b[0] = a[0];
    int mini = a[0];
    for (int i = 1; i < N; i++) {
        bool flag = false;
        if (a[i] <= mini) {
            b.push_back(a[i]);
            mini = a[i];
            continue;
        }
            

        for (int j = 0; j < b.size(); j++) {
            if (a[i] > b[j]) {
                b[j] = a[i];
                flag = false;
                break;
            }
            else {
                flag = true;
            }
        }
        if (flag){ 
            b.push_back(a[i]);
            if (mini >= a[i]) mini = a[i];
        }
    }
    
    cout << b.size() << endl;

}
