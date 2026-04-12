#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;
using P = pair<int,int>;
const int MOD = 1000000007;

int main() {
    int h,w;
    cin>>h>>w;
    char a[h][w];
    vector<bool> row(h,false);
    vector<bool> cal(h,false);
    rep(i,h) {
        rep(j,w) {
            cin>>a[i][j];
            if (a[i][j]=='#') {
                row[i]=true;
                cal[j]=true;
            }
        }
    }
    rep(i,h) {
        if (row[i]) {
            rep(j,w) {
                if (cal[j]) cout<<a[i][j];
            }
            printf("\n");
        }
    }
}   
