#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int main() {
    string S;
    cin >> S;
    int cnt = count(S.begin(), S.end(), 'A');
    if (cnt == 3 || cnt == 0) cout << "No";
    else cout << "Yes";
}