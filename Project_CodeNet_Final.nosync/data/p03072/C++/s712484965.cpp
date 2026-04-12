#include <bits/stdc++.h>
using namespace std;
int main() {
    int n = 0;
    cin >> n;
    int max = 0;
    int enter = 0;
    int counter = 0;
    for(int i = 0; i < n; i++) {
        cin >> enter;
        if(enter >= max) {
            max = enter;
            counter++;
        }
    }
    cout << counter << endl;
    return 0;
}