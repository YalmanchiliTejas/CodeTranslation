#include <bits/stdc++.h>
using namespace std;

int main() {
    string i;
    getline(cin, i);
    //4 3 2cout << i << endl;


    i.erase (remove (i.begin(), i.end(), ' '), i.end());

    int s = atoi(i.c_str());
    //cout << s << endl;

    if (s % 4 == 0) {
        cout << "YES" << endl;
    }
    else {
        cout << "NO" << endl;
    }

}