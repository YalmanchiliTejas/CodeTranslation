#include<bits/stdc++.h>
using namespace std;
int main()
{
    int a,b,c;
    cin>>a>>b>>c;
    string aa=to_string(a);
    string bb=to_string(b);
    string cc=to_string(c);
    string ans=aa+bb+cc;
    int pp=stoi(ans);
    if(pp%4==0)
        cout<<"YES"<<endl;
    else
        cout<<"NO"<<endl;
return 0;
}
