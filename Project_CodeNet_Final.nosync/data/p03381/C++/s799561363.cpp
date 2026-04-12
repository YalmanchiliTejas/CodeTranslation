#include <iostream>
#include <algorithm>
using namespace std;

int main() {

    int n, x[200001], od[200001];
    long long sum[200002] = {0};

    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> x[i];
        od[i - 1] = x[i];
    }


    sort(od, od + n);
    for(int i = 1; i <= n; i++) {
        if(x[i] <= od[(n + 1) / 2 - 1]) {
            cout << od[(n + 1) / 2] << endl;
        } else {
            cout << od[(n + 1) / 2 - 1] << endl;
        }
    }
}
