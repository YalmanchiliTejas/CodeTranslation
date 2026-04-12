#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i < (int)(n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main(){
    string s;
    cin >> s;
    if(s == "AAA") cout << "No" << endl;
    if(s == "AAB") cout << "Yes" << endl;
    if(s == "ABB") cout << "Yes" << endl;
    if(s == "ABA") cout << "Yes" << endl;
    if(s == "BBA") cout << "Yes" << endl;
    if(s == "BAB") cout << "Yes" << endl;
    if(s == "BAA") cout << "Yes" << endl;
    if(s == "BBB") cout << "No" << endl;
    return 0;
}