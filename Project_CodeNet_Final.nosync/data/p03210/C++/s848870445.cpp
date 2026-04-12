#include <fstream>
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
#include <set>

#define rep(i,n) for (int i = 0; i < (n); ++i)
#define sz(x) int(x.size())

using namespace std;
typedef long long ll;

int main(int argc, const char * argv[]) {
//    ifstream in("input.txt");
//    cin.rdbuf(in.rdbuf());
    
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int x;
    cin >> x;
    
    if (x == 7 || x == 5 || x == 3) cout << "YES" << endl;
    else cout << "NO" << endl;
    
    return 0;
}