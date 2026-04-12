#include <iostream>
#include <set>
using namespace std;

int main()
{
    char c;
    cin >> c;
    set<char> st = {'a', 'i', 'u', 'e', 'o'};
    if (st.find(c) != st.end()) cout << "vowel" << endl;
    else cout << "consonant" << endl;

    return 0;
}
