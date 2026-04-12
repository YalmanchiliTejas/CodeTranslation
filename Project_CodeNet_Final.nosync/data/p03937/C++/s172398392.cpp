#include <bits/stdc++.h>
using namespace std;

using str = string;
using ss = stringstream;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    int h,w;cin>>h>>w;

    int m=0;
    bool ans=true;
    for(int i=0;i<h;i++)
    {
        str s;cin>>s;
        int bm=m;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='#')
            {
                if(i<m)ans=false;
                else bm=i;
            }
        }
        m=bm;
    }

    puts(ans?"Possible":"Impossible");

    return 0;
}
