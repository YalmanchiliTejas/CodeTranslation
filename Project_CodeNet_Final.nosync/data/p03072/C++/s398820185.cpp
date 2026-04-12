#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> h(n);
    for (int i = 0; i < n; i++){
        cin >> h.at(i);
    }

    int high = 0;
    int ans = 0;

    for (int i = 0; i < n; i++){
        if (high <= h[i]){
            high = h[i];
            ans++;
        }
    }
    cout << ans << endl;
}