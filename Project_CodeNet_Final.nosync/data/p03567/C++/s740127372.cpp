#include "bits/stdc++.h"
using namespace std;
const int maxn = 55;
char grid[maxn][maxn];
int M(){
    string s;
    if(!(cin >> s)) return 0;
    if(s.find("AC") != -1) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 1;
}
int main(){
    while(M());
    return 0;
}
