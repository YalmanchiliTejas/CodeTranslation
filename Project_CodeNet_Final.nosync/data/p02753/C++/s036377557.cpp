#include <iostream>
#include <string>
#include <cstdint>
#include <cmath>
#include <vector>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <climits>
#include <numeric>
#include <algorithm>

using namespace std;


int main()
{
    string s;
    cin >> s;
    
    cout << (s[0] == s[1] && s[1] == s[2] ? "No" : "Yes") << '\n';
    return 0;
}
