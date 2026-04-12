#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <map>
#include <string>

using namespace std;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    int d[n];
    for(int i = 0; i < n; i++) {
        cin >> d[i];
    }
    int l = 0;
    bool ok = false;
    for(int i = 0; i < n; i++) {
        if(l < 0) break;
        if(i == n-1) ok = true;
        l = max(l,d[i]);
        l -= 10;
    }
    if(!ok) {
        cout << "no" << endl;
        return 0;
    }
    l = 0;
    ok = false;
    for(int i = n-1; i >= 0; i--) {
        if(l < 0) break;
        if(i == 0) ok = true;
        l = max(l,d[i]);
        l -= 10;
    }
    if(!ok) {
        cout << "no" << endl;
        return 0;
    }

    cout << "yes" << endl;

}