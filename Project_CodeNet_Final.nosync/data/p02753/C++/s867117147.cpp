#include <bits/stdc++.h>

using namespace std;
#define int long long int



signed main()
{
    string s;
    cin >> s;
    int ln = s.length();
    for(int i = 0; i < ln; i++){
        if(s[0] == 'A' && s[1] == 'A' && s[2] == 'A' || s[0] == 'B' && s[1] == 'B' && s[2] == 'B'){
            cout << "No"<< endl;
            break;
        }
        else{
            cout << "Yes"<< endl;
            break;
        }
    }
    return 0;
}
