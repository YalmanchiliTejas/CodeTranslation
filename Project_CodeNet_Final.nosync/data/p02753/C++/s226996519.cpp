#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    string a;
    cin>>a;
    set<char>s;
    for(int i=0; i<a.size(); i++)
    {
        s.insert(a[i]);
    }
    if(s.size()==2)
    {
        cout<<"Yes"<<endl;
    }
    else
    {
        cout<<"No"<<endl;
    }
}
