# include <iostream>
# include <string>
# include <set>
# include <algorithm>

using namespace std;

int main () {
    string s;
    cin >> s;
    set <char> set;
    for (char i : s) set.insert(i);
    if (set.size() == 2) cout << "Yes\n";
    else cout << "No\n";
    return 0;
}