#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#include <unordered_map>
#include <set>
#include <climits>
using namespace std;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int r, g, b;
    cin >> r >> g >> b;
    int aa = 100 * r + 10 * g + b;
    if(aa % 4 == 0){
        cout << "YES" << endl;
        return 0;
    }
    cout << "NO" << endl;
    return 0;
}