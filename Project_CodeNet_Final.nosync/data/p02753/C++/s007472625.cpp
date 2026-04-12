#include<bits/stdc++.h>
using namespace std;

#define FastRead        ios_base::sync_with_stdio(false);cin.tie(NULL);
#define endl            "\n"

typedef long long ll;
typedef unsigned long long llu;

int main()
{
    FastRead
    string s;

    bool flag=false,ribbon=false;

    cin>>s;

    for(ll i=0;i<s.size();i++)
    {
        if(s[i]=='A')
            flag = true;
        else
            ribbon = true;
    }

    if(flag and ribbon)
        cout<<"Yes";
    else
        cout<<"No";
}
