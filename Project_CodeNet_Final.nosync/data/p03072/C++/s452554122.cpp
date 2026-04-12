#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> h(n);
    for(auto& e : h) {
        cin >> e;
    }
    int ans = 0;
    for(int i=0; i<n; i++) {
        bool see = true;
        for(int j=i; j>=0; j--) {
            if(h[j] > h[i]) see = false;
        }
        if (see) ans++; 
    }
    cout << ans << endl;
}