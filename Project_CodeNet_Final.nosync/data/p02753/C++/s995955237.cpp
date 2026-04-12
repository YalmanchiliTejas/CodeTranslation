#include<iostream>
#include<string>
using namespace std;

int main(){
    string S;
    cin >> S;
    bool ans = false;
    if (S[0] != S[1])ans = true;
    if (S[1] != S[2])ans = true;
    if (S[2] != S[0])ans = true;
    if (ans)cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}