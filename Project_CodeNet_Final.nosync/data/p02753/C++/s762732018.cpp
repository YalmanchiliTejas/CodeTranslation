#include<bits/stdc++.h>
using namespace std;
#define F(i,s,e) for(int i=s;i<e;++i)

int main()
{
    string s;
    cin >> s;
    if(s[0]==s[1]&&s[1]==s[2]) cout << "No" << endl;
    else cout << "Yes" << endl;
    return 0;
}