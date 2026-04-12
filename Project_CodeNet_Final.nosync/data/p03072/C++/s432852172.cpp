#include <iostream>
#include<bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    int max_v = 0;
    int a;
    int r = 0;
    for (int i = 0; i < N;i++) {
        cin >> a;
        max_v = max(a, max_v);
        if (a >= max_v)
        {
            r++;
        }
    }
    cout << r;
    return 0;
}