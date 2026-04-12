#include <bits/stdc++.h>
using namespace std;


int main()
{
    string s;
    cin>>s;
    int c[2]={0};
    for(int i=0;i<3;i++)
    {
        int co=s[i]-'A';
        c[co]++;
    }
    if(c[0]>0 && c[1]>0) cout<<"Yes";
    else cout<<"No";
}
