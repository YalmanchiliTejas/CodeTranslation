#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
#include <set>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i=0;i < (int)(n);i++)


int main(){
    int x,y,z;
    cin >> x >> y >> z;
    if (x%(y+z) < z) cout << x/(y+z)-1 << endl;
    else cout << x/(y+z) << endl;  

    return 0;
}