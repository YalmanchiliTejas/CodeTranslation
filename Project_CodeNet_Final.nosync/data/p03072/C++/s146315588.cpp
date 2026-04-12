#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <stdio.h>

using namespace std;

void solve() {
    int n; cin >> n;
    vector<int> h(n);
    for(int i = 0; i < n; i++){
        cin >> h[i];
    }
    int count = 1;
    for(int i = 1; i < n; i++){
        bool flag = true;
        for(int j = 0; j < i; j++){
            if(h[i] < h[j]){
                flag = false;
                break;
            }
        }
        if(flag) count++;
    }
    cout << count << endl;
}

int main() {
    solve();
    return 0;
}