#include <iostream>
#include <set>
using namespace std;

int main() {
    string s; cin >> s;
    set<int> S;
    for (int i = 0; i < 3; i++) S.insert(s[i]);
    if (S.size() > 1) puts("Yes");
    else puts("No");
}