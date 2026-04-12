#include "bits/stdc++.h"
using namespace std;
#define REP(i, n) for (int i = 0; i < (n); i++)
#define ll long long

int main()
{
    string S;
    bool t=false;
    cin >> S;
    REP(i,2) {
        if(!(S[i]==S[i+1])) {
            t=true;
            break;
        }
    } 
    if(t) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}