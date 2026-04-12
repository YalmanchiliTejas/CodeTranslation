#include <functional>
#include <iostream>
#include <numeric>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    string t, p;
    cin >> t;
    cin >> p;

    t += "$";
    p += "$";

    vector<bool> exists(p.size());
    bool duplicated = false;
    int i = 0;
    char tmp = '!';
    for (int j = 0; j < t.size(); ++j) {
        if (p[i] == t[j]) {
            if (!exists[i]) {
                exists[i] = true;
                tmp = p[i];
                i += 1;
            }
        }
        else if (tmp == t[j]) {
            duplicated = true;
        }
        else {
            if (exists[i]) {
                i += 1;
            }
        }
    }

    if (accumulate(begin(exists), end(exists), true, logical_and<>())) {
        if (!duplicated) {
            cout << "yes" << endl;
            return 0;
        }
    }
    cout << "no" << endl;
}