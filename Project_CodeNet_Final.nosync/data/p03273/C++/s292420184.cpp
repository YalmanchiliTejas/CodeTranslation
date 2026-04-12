#include <bits/stdc++.h>
using namespace std;

using str = string;
using ss = stringstream;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    int h,w;cin>>h>>w;

    ss makeblank;
    for(int i=0;i<w;i++)makeblank<<'.';
    str blank=makeblank.str();

    vector<str> m;

    for(int i=0;i<h;i++)
    {
        str s;cin>>s;

        if(s!=blank)m.push_back(s);
    }

    vector<ss> mm(m.size());

    for(int i=0;i<w;i++)
    {
        bool c=true;
        for(auto im:m)if(im[i]=='#')c=false;
        if(!c)for(int j=0;j<m.size();j++)mm[j]<<m[j][i];
    }

    m.clear();

    for(int i=0;i<mm.size();i++)m.push_back(mm[i].str());

    for(auto im:m)cout<<im<<"\n";

    return 0;
}
