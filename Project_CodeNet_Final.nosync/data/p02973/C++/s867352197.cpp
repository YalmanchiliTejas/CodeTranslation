#include <bits/stdc++.h>
using namespace std;

int main(){
    int n; cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    multiset<int> s; 
    for(int i = 0; i < n; i++){
        int tmp = a[i];
        auto it = s.lower_bound(tmp);
        if(it != s.begin()) s.erase(--it);
        s.insert(tmp);
    }
    cout << s.size() << endl;
}