#include <iostream>

using namespace std;
string s;
int ok,i;
int main()
{
    cin>>s;ok=0;
    for(i=0;i<s.size()-1;i++)
        if(s[i]=='A'&&s[i+1]=='C')
         ok=1;
    if(ok) cout<<"Yes";
    else cout<<"No";
    return 0;
}