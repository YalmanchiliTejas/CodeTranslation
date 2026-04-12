#include <bits/stdc++.h>
#define rep(i,n) for(long long int i = 0; i < n; i++)
#define print(n) std::cout << n << std::endl
#define _print(n) std::cout << n
using namespace std;
const int N = 1000000;


int main() {
   int h,w; cin >> h >> w;

   vector<string> a(h);
   rep(i,h) cin >> a[i];

   vector<bool> r(h,false);
   vector<bool> c(w,false);

    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            if(a[i][j] == '#'){
                r[i] = true;
                c[j] = true;
            }
        }
    }

    for (int i = 0; i < h; ++i) {
        if(r[i]){
            for (int j = 0; j < w; ++j) {
                if(c[j]){
                    cout << a[i][j];
                }
            }
            cout << endl;
        }
    }
}