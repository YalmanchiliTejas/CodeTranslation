#include <iostream>
#include <string>

using namespace std;

bool judge (char c)
{
    if (c=='y' || c=='u' || c=='i' || c=='o' || c=='p' || c=='h' || c=='j' || c=='k' || c=='l' || c=='n' || c=='m') return true;
    else return false;
}

int main()
{
    while (1)
    {
        int ans=0; bool hand;
        string s; char c;
        cin>>s;
        if (s=="#") break;
        c=s[0];
        hand=judge(c);
        for (int i=1; i<s.size(); i++)
        {
            c=s[i];
            if (judge(c)!=hand) { ans++; hand=!hand; }
        }
        cout<<ans<<'\n';
    }
    return 0;
}

