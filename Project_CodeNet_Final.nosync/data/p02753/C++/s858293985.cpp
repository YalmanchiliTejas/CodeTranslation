#include<bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    cin>>s;
    for(int i=0;i<s.size();i++){
        if((s[0]=='A' && s[1]=='A' && s[2]=='A') || (s[0]=='B' && s[1]=='B' && s[2]=='B'))
        {
            printf("No\n");
            return 0;
        }
        else{
           printf("Yes\n");
           return 0;
        }

    }
    return 0;
}
