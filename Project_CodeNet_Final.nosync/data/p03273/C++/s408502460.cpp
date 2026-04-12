#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;

int main() {
    int h,w;
    cin>>h>>w;
    vector<string> a(h);
    
    rep(i,h) cin >> a[i];
    vector<bool> row(h, 0);
    vector<bool> col(w, 0);
    rep(i,h) {
       rep(j,w) {
           if (a[i][j] == '#') {
               row[i] = 1;
               col[j] = 1;
           }
       }
    }
    
    rep(i,h) {
        if(row[i]){
            rep(j,w){
                if(col[j]){
                    cout << a[i][j];
                }
            }
            cout << endl;
        }
    }
    return 0;
}
