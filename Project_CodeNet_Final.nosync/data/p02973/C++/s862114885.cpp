#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n; cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    vector<int> s;
    for(int i = n-1; i >= 0; i--){
        int idx = upper_bound(s.begin(), s.end(), a[i]) - s.begin();
        if(idx == s.size()){
            s.push_back(a[i]);
        }
        else{
            s[idx] = a[i];
        }
    }
    cout << s.size() << endl;
    return 0;
}