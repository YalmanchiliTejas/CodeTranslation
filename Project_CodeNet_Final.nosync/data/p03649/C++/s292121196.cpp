#include <iostream>
using namespace std;

int main() {

    int n;
    long long a[50];

    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }


    long long cnt = 0;
    bool update = true;
    while(update) {
        update = false;
        for(int i = 0; i < n; i++) {
            if(a[i] >= n) {
                cnt += a[i] / n;
                for(int j = 0; j < n; j++) if(i != j) a[j] += a[i] / n;
                a[i] %= n;
                update = true;
            }
        }
    }
    cout << cnt << endl;
}
