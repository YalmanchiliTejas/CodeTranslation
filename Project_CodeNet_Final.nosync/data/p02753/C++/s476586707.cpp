#include<bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    cin>>s;
    set<char> st;
    for(int i=0;i<s.size();i++)
    {
       st.insert(s[i]);
    }
    if(st.size()==1)
        cout<<"No"<<endl;
    else
        cout<<"Yes"<<endl;
}
