#include <algorithm>
#include <deque>
#include <iostream>
#include <map>
#include <math.h>
#include <string.h>
#include <vector>

using namespace std;
int main() {
    int X;
    string ans;
    cin >> X;
    if(X==7||X==5||X==3) {
        ans = "YES";
    }else{
        ans="NO";
    }
    cout << ans << endl;
    return 0;
}