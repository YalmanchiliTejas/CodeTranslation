#include <iostream>
#include <string>
#include <set>
#include <algorithm>
using namespace std;

int main() {

    int n,m;

    cin >> n >> m;
    bool ans = n == m;
    cout << (ans ? "Yes" : "No") << endl;
}