#include <bits/stdc++.h>
using namespace std;

int main() {
    
    while (1) {
        int x;
        cin >> x;
        if (!(x)) break;
        
        int min, max, avg = 0;
        for (int i = 0; i < x; i++) {
            int num;
            cin >> num;
            if (!(i)) {
                min = num;
                max = num;
            } else {
                if (num < min) min = num;
                if (num > max) max = num;
            }
            avg += num;
        }
        
        avg -= (min + max);
        avg /= (x - 2);
        cout << avg << endl;
    }
}
