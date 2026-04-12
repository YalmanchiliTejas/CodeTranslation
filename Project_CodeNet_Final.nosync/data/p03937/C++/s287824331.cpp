#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ll h,w,tmp=0;
    cin>>h>>w;
    vector<vector<char>> a(h,vector<char>(w));
    bool flag = true;
    for(int i=0; i<h; i++) {
        for(int j=0; j<w; j++) cin>>a[i][j];
    }
    for(int i=0; i<h; i++) {
        for(int j=0; j<w; j++) {
            if(a[i][j] == '#') {
                if(tmp > j) flag = false;
                else tmp = j;
            }
        }
    }
    cout<<(flag == true ? "Possible" : "Impossible")<<endl;
}