#include<iostream>
using namespace std;

int main()
{
    string s;
    bool a=false,b=false;

    cin>>s;

    for(int i=0;i<3;i++){
        if(s[i]=='A')a=true;
        else if(s[i]=='B')b=true;
    }

    if(a && b)cout<<"Yes";
    else cout<<"No";
    return 0;
}
