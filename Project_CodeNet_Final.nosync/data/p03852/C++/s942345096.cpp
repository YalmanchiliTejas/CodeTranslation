#include <iostream>
#include <string>
#include <vector>
#include <set>
using namespace std;
 
int main() {
    set<char> V = {'a', 'e', 'i', 'o', 'u'};
    char c;
    cin >> c;
    if(V.find(c) != V.end()) cout << "vowel";
    else cout << "consonant";
    cout << endl;
}
