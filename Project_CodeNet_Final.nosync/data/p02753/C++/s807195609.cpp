# include <cmath>
# include <iostream>
# include <queue>
# include <set>
# include <stack>
# include <string>
# include <vector>


using namespace std;


int main() {
    string s; cin >> s;
    if (s[0] != s[1] or s[1] != s[2]) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}

