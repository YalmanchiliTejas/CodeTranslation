#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main()
{
    string s;
    cin >> s;

    if(s[0] == s[1] && s[1] == s[2] && s[0] == s[2]){
        cout << "No";
        return 0;
    }
    cout << "Yes";
    
    return 0;
}
