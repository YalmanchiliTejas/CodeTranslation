#include <bits/stdc++.h>
using namespace std;

string s;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> s;
    for(int i = 0 ; i < s.size()-1 ; i++)
        if(s[i] == 'A' && s[i+1] == 'C') return cout << "Yes" << endl, 0;
    cout << "No" << endl;
    return 0;
}
