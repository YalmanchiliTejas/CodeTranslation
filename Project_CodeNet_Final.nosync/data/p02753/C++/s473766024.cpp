#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>

using namespace std;


int main()
{
    string s;
    cin >> s;

    unordered_set<char> x(s.begin(), s.end());
    cout << (x.size() == 1 ? "No" : "Yes") << endl;
}
