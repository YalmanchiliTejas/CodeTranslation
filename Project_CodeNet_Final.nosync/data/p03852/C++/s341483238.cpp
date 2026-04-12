#include <bits/stdc++.h>

using namespace std;

int main() {
    char x;
    cin >> x;

    set<int> st = {'a', 'e', 'i', 'o', 'u'};
    st.erase(x);
    if (st.size() != 5) {
        cout << "vowel" << endl;
    } else {
        cout << "consonant" << endl;
    }
    return 0;
}
