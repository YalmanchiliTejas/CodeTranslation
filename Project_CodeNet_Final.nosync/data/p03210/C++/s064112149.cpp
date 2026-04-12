#include <iostream>
#include <fstream>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <vector>
#include <algorithm>
#include <cmath>
#include <chrono>

using namespace std;

int main(int argc, const char * argv[]) {
    
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int x; cin >> x;
    
    cout << (x == 7 || x == 5 || x == 3 ? "YES" : "NO") << endl;
    
    return 0;
}
