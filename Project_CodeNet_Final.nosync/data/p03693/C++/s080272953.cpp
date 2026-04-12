#include<iostream>
#include<map>
#include<vector>
#include<algorithm>

#define dump(x)  cerr << #x << " = " << (x) << endl;
#define debug(x) cerr << #x << " = " << (x) << " (L" << __LINE__ << ")" << " " << __FUNCTION__ << endl;
#define int long long

using namespace std;

signed main(){
    int r, g, b;
    cin >> r >> g >> b;
    cout << (((r * 100 + g * 10+ b) % 4 == 0)? "YES" : "NO");
    return 0;
}
