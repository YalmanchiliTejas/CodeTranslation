#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main(){
    int n;
    cin >> n;
    
    vector<int> h(n);
    rep(i, n){
        cin >> h.at(i);
    }
    
    int max_h = 0, count = 0;
    rep(i, n){
        max_h = max(max_h, h.at(i));
        if(h.at(i) >= max_h) count++;
    }
    
    cout << count << endl;
    return 0;
}