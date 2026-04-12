#include <bits/stdc++.h>
using namespace std;

#define REP(i, start, count) for(int i=(start); i<(int)(count); ++i)
#define rep(i, count) REP(i, 0, count)
#define ALLOF(c) (c).begin(), (c).end()

typedef long long ll;
typedef unsigned long long ull;

string S;

int main(void) {
    
    cin >> S;

    if (S == "AAA" || S == "BBB") {
        cout << "No" << endl;
    }
    else {
        cout << "Yes" << endl;
    }
    return 0;
} 