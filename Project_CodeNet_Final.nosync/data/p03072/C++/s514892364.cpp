#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int>high(n);
    for (int i = 0; i < n; i++) {
        cin >> high.at(i);
    }
    int count = 0;
    for (int i = 0; i < n; i++) {
        bool okey = true;
        for (int j = 0; j < i; j++) {
            if (high.at(i) < high.at(j)) {
                okey = false;
            }
        }
        if (okey) {
            count++;
        }
    }
    cout << count << endl;
}
