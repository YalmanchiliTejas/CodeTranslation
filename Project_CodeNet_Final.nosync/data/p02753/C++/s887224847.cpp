#include <bits/stdc++.h>
 
using namespace std;
#define ll long long
#define ld long double
 
int main()
{
    ios_base::sync_with_stdio(0),cin.tie(NULL),cout.tie(NULL);
    string s;
    cin >> s;
    bool okA = false, okB = false;
    for(int i=0;i<3;i++) {
        if(s[i] == 'A') okA = true;
        else if(s[i] == 'B') okB = true;
    }
    if(okA && okB) cout << "Yes" << endl;
    else cout << "No" << endl;
}
