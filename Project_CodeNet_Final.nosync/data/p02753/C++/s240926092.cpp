#include <algorithm>
#include <cmath>
#include <deque>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <set>
#include <stack>
#include <string>
#include <unordered_set>
#include <vector>

using namespace std;
using LLONG = long long;
const LLONG MOD = 1000000007;

int main()
{
    string S; cin >> S;
    if (S[0] != S[1]) cout << "Yes" << endl;
    else if (S[1] != S[2]) cout << "Yes" << endl;
    else cout << "No" << endl;
}
