#include <bits/stdc++.h>

using namespace std;

int main() {
    char S[3];
    cin >> S;
    int a,b;

    for(int i=0;i<3;i++){
        if(S[i]=='A') a++;
        if(S[i]=='B') b++;
    }   
    string res =  (a*b) != 0?"Yes":"No";
    cout << res;

}