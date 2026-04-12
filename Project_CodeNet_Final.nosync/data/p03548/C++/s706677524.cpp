
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)



int main(){
    int x, y, z;
    cin >> x >> y >> z;
    rep(i,x){
        if(x - y*i - z*(i+1) >= 0){
            continue;
        }
        else{
            cout << i-1 << endl;
            return 0;
        }
    }
}