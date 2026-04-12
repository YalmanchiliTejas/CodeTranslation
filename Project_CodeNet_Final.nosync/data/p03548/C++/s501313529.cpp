#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0;i < (n);i++)
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pil = pair<pii,int>;


int main(){
    int x,y,z;
    cin >> x >> y >> z;
    x -= z;
    cout << x/(y+z) << endl;
}