#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define REP(i, a, b) for(int i = a, i##_len = (b); i < i##_len; ++i)

int main()
{
    string S;
    cin >> S;
    for(int i = 0; i + 1 < S.size(); ++i) {
        if(S.substr(i,2)=="AC") {
            cout << "Yes" << endl;
            return 0;
        }
    }
    cout << "No" << endl;
    return 0;
}