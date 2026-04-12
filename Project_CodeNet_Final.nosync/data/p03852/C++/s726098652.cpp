#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<char> v = {'a', 'e', 'i', 'o', 'u'};
    char c;
    cin >> c;
    if (find(v.begin(), v.end(), c) != v.end()) {
        cout << "vowel\n";
    } else {
        cout << "consonant\n";
    }
}