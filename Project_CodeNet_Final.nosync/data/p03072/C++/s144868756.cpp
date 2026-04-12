#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> v(n);
    for(int i=0; i<n; i++) cin >> v[i];
    int count = 0;
    bool tall;

    for(int i=0; i<v.size(); i++) {
        for(int j=0; j<=i; j++) {
            if(v[i]<v[j]) {
                tall = false;
                break;
            }
            else tall = true;
        }
        if(tall) count++;
    }
    cout << count << endl;
}

