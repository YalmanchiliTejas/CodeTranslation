#include <bits/stdc++.h>

using namespace std;

int main() 
{   
        string s;
        int a=0,b=0;
        cin>>s;
        for (int i=0;i<s.length();i++)
        {
            if (s[i] == 'A') a++;
            if (s[i] == 'B') b++;
        }
        if (a==0 || b==0) cout<<"No"<<endl;
        else    cout<<"Yes"<<endl;
        return 0;
}