#include<bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    cin>>s;
    for(int i=0;i<s.length();i++){
        if(i+1<s.length() && s[i]=='A' && s[i+1]=='C'){
            return cout<<"Yes"<<endl,0;
        }
    }
    cout<<"No"<<endl;
return 0;
}
