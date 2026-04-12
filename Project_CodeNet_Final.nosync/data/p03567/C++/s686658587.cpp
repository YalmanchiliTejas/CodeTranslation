#include<bits/stdc++.h>
using namespace std;
string a;
int main()
{
    cin>>a;
    for(int i=0;i<a.size()-1;i++)if(a[i]=='A'&&a[i+1]=='C')
    {
        cout<<"Yes";return 0;
    }
    cout<<"No";
}