#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; i++)
#define inf 1000000000
typedef long long ll;

int main()
{
    string s;
    cin>>s;
    if(s[0]==s[1]&&s[0]==s[2]){
        cout << "No" << endl;
        return 0;
    }
    cout << "Yes" << endl;
    return 0;
}