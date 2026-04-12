#include <bits/stdc++.h>

using namespace std;

int main() {

    int n;
    cin >> n;
    
    int max = 0, cnt = 0;
    for(int i = 0; i < n; i++) {
        int height;
        cin >> height;
        
        if(height >= max) {
            max = height;
            cnt++;
        }
    }
    
    cout << cnt << endl;
    return 0;
}