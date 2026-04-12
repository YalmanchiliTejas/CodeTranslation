#include <iostream>
#include <set>
#include <initializer_list>

using namespace std;

int main()
{
    string s;
    set<char> right = {'y', 'u', 'i', 'o', 'p', 'h', 'j', 'k', 'l', 'n', 'm'};
    while (cin >> s, s!="#") {
        int lastr = right.count(s[0]);
        int count = 0;
        for (char c: s) {
            int key = right.count(c);
            if (key != lastr) {
                lastr = key;
                count++;
            }
        }
        cout << count << endl;
    }
    return 0;
}