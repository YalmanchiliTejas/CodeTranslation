#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <queue>
#include <map>
#include <set>
#include <algorithm>
#include <numeric>
#include <cmath>
#include <bitset>
#include <iomanip>

using namespace std;
typedef long long ll;
typedef unsigned long long ull;

int main(int argc, const char * argv[]) {
    string S;
    cin >> S;
    if (S[0] == S[1] && S[1] == S[2]) {
        cout << "No" << endl;
    } else {
        cout << "Yes" << endl;
    }

    return 0;
}