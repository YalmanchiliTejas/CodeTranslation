#include <bits/stdc++.h>
using namespace std;

int main(){
    string S;
    cin >> S;
    set<char> SET;
    for(int i=0;i<3;i++) SET.insert(S[i]);
    cout << (SET.size() == 2 ? "Yes" : "No") << endl;
}