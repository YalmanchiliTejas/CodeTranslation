#include <iostream>
#include <cmath>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <utility>
#include <vector>
#include <algorithm>

typedef long long ll;

using namespace std;

int main() {
    string S;
    cin >> S;
    cout << (S[0] != S[1] || S[1] != S[2] ? "Yes" : "No") << endl;
    return 0;
}

