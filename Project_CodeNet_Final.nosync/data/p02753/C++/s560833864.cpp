#include <bits/stdc++.h>
 
int main(){
    using namespace std;
    string S;
    cin >> S;

    if (S[0] == S[1] && S[1] == S[2]) cout << "No" << endl;
    else cout << "Yes" << endl;

    return 0;
}