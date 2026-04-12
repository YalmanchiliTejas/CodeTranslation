#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    vector<int> h(25), l(25);

    cin >> n;

    int max_h = 0, count = 0;
    for (int i = 0; i < n; i++){
        cin >> h[i];
        max_h = max(max_h, h[i]);
        if (max_h == h[i]){
            count += 1;
        }
    }

    cout << count;
    return 0;
}