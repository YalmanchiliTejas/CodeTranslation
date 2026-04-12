#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <numeric>
#include <functional>
#include <cmath>
#include <string>

using namespace std;
int main(int argc, const char * argv[]) {
    
    string s;
    int n, k;

    cin >> n >> s >> k;

    for (int i=0; i<s.size(); i++) {
        if (s[k-1]!=s[i]) cout << "*";
        else cout << s[i];
    }
    cout << endl;
    return 0;
}