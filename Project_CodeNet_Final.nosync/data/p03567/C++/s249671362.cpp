#include<bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    int x=0;
    cin>>s;
    for(int i=0;i<s.size();i++){
        if(x==1&&s[i]=='C'){
            cout<<"Yes"<<endl;
            return 0;
        }
        if(s[i]=='A') x=1;
        else x=0;
    }
    cout<<"No"<<endl;
    return 0;
}
