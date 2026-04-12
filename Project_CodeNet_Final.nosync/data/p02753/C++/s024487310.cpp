#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    set<char>s;
    string str;
    cin>>str;
    for(int i=0;i<str.size();i++)
    {
        s.insert(str[i]);
    }
    if(s.size()==1)
    {
        cout<<"No"<<endl;
    }
    else
    {
        cout<<"Yes"<<endl;
    }
    return 0;
}