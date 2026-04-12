#include <bits/stdc++.h>
using namespace std;
int n,m;
string a;
int main()
{
    cin>>a;
    int is=0,is1=0;
    for(int i=0;i<a.size();i++)
    {
        if(a[i]=='A'&&a[i+1]=='C')
        {
            cout<<"Yes";return 0;
        }
    }
 cout<<"No";
}
