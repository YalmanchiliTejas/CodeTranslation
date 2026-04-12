#include <iostream>
#include <fstream>
#include <random>
#include <utility>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <map>
#include <algorithm>

using namespace std;



int main() {

    //freopen("../input.txt", "r", stdin);

    ios::sync_with_stdio(false);
    cin.tie();
    cout.tie();

    string s;
    cin >> s;

    if (s == "AAA" || s == "BBB") {
        cout << "No";
    } else {
        cout << "Yes";
    }

    return 0;
}