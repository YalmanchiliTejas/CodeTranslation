#include <bits/stdc++.h>
using namespace std;

int main(){
    int x, y, z;
    cin >> x >> y >> z;
    
    int count = 0, sum = z;
    while (sum < x) {
        sum += y + z;
        if (sum <= x) {
            count++;
        }
    }
    
    cout << count << endl;
    return 0;
}
