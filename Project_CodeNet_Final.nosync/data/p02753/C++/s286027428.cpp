#include<bits/stdc++.h>

using namespace std;

int main() {
    set<char>s;
    for (int i = 0; i < 3; i++) {
        char d;
        cin >> d;
        s.insert(d);
    }
    if(s.size() >= 2) {
        cout << "Yes"<<endl;
    }
    else {
        cout << "No" << endl;
    }
    return 0;
}

