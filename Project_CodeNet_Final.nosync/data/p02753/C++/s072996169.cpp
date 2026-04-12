#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

// static const int MAX = 1e6;
// static const int NIL = -1;
// static const ll INF = 1<<21;
// static const ll MOD = 1e9 + 7;

bool compPair(const pair<int, int>& arg1, const pair<int, int>& arg2) {
    return arg1.first > arg2.first;
}

int main(void) {
    string ss;
    cin >> ss;
    if(ss.at(0)!=ss.at(1)||ss.at(1)!=ss.at(2)||ss.at(0)!=ss.at(2)) {
        cout << "Yes" << endl;
    }
    else cout << "No" << endl;
    
    return 0;
}
