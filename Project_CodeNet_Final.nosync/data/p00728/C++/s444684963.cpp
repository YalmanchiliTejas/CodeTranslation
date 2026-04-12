#include <iostream>
#include <algorithm>
using namespace std;
int main(void){
    while (1) {
        int n;
        cin >> n;
        if (n == 0) return 0;
        
        int q[1005], sm = 0;
        for (int i = 0; i < n; i++) {
            cin >> q[i];
            sm += q[i];
        }
        
        sort(q, q + n);
        
        cout << (sm - q[0] - q[n - 1]) / (n - 2) << endl;
    }
}

