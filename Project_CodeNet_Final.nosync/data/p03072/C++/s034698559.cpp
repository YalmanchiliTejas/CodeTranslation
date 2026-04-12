#include<bits/stdc++.h>

using namespace std;

int main()
{
    set<int>s;
    int n,h,chk=0,c=0;
    cin>>n;
    for(int i=0; i<n; i++)
    {
        cin>>h;
        chk=max(chk,h);

        if(h>=chk)
        {
            c++;
        }
    }
    cout<<c;
    return 0;
}
