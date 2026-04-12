#include"bits/stdc++.h"
using namespace std;

int main(){
    int n;
    cin >> n;
    int k;
    int ans;
    while(n!=0){
        vector<int> a;
        for (int i = 0; i<n; i++){
            cin >> k;
            a.push_back(k);
        }
        sort(a.begin(), a.end());
        ans = 0;
        for (int i = 1; i<n-1; i++) ans += a[i];
        cout << ans/(n-2) << endl;
        cin >> n;
    }
}

