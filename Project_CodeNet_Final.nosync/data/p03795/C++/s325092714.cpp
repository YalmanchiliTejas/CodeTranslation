#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main(int argc, const char * argv[]) {
    // insert code here...
    int N;
    cin >> N;
    
    int x = 0, y = 0;
    
    for (int i = 1; i <= N; i++) {
        x += 800;
        if (i % 15 == 0) y += 200;
    }
    
    cout << x - y << endl;
    
    return 0;
}
