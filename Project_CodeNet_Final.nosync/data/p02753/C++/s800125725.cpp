#include <bits/stdc++.h>
using namespace std;
int main(){
    string S;
    cin >> S;
    int ca = 0;
    int cb = 0;
    for(int i = 0; i < S.size(); ++i){
        if(S[i] == 'A') ca++;
        else cb++;
    }
    if(ca && cb) cout << "Yes";
    else cout << "No";
    return 0;
}