#include <iostream>
using namespace std;
char rAnimal(char flag, char cAnimal, char lAnimal)
{
    if(flag=='o')
    {
        if(cAnimal=='S')
            return lAnimal;
        else
        {
            if(lAnimal=='S')
                return 'W';
            else
                return 'S';
        }
    }
    else
    {
        if(cAnimal=='W')
            return lAnimal;
        else
        {
            if(lAnimal=='S')
                return 'W';
            else
                return 'S';
        }
    }
}
int main(int argc, const char * argv[])
{
    string t[4]={"SS","SW","WS","WW"},s,ans;
    int n;
    cin>>n>>s;
    bool found=false;
    for(int k=0;k<4;k++)
    {
        found=true;
        ans=t[k];
        for(int i=2;i<n;i++)
        {
            char next=rAnimal(s[i-1], ans[i-1], ans[i-2]);
            ans.push_back(next);
        }
        
        if(ans[0]!=rAnimal(s[n-1], ans[n-1], ans[n-2]))
        {
            found=false;
            continue;
        }
        if(ans[1]!=rAnimal(s[0], ans[0], ans[n-1]))
        {
            found=false;
            continue;
        }
        if(found)
            break;
    }
    if(found)
        cout<<ans<<endl;
    else
        cout<<-1<<endl;
    return 0;
}