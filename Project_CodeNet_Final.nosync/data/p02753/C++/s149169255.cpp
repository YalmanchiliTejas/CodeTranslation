#include<bits/stdc++.h>
using namespace std;
#define lli long long int
#define mod 1000000007


void solve(string str)
{
    int n=str.length();
    set<int> a;
    set<int> b;
    int i=0;
    while(str[i]!='\0')
    {
        if(str[i]=='A')
        {
            a.insert(i);
        }
        else if(str[i]=='B')
        {
            b.insert(i);
        }
        i++;
    }
    if(!a.empty() && !b.empty() )
    {
        cout<<"Yes"<<"\n";
    }
    else{
        cout<<"No"<<"\n";
    }


}
int main()
{
    string str;
    cin>>str;;
    solve(str);
    return 0;
}
