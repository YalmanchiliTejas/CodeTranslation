#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define rep(i,s,e) for(int (i) = (s);(i) <= (e);(i)++)

int x,y,z;
int main(){
    cin >> x >> y >> z;
    int ans = (x - z) / (y + z);
    cout << ans << endl;
}