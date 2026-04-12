#include <bits/stdc++.h> 
using namespace std; 
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    string s;
    int flag1 = 0, flag2 = 0;
    cin>>s;

    for(int i=0;i<s.length();i++)
    {
        if(s[i] == 'A')
        flag1++;

        else if(s[i] == 'B')
        flag2++;
    }

    if(flag1 > 0 && flag2 > 0)
    cout<<"Yes\n";

    else 
    cout<<"No\n";
	return 0; 
} 
