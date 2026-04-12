#include <bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    cin>>s;
    bool b=0;
    bool e=0;
    for(int i=0;i<3;i++){
        if(s[i]=='A'){b=1;}
        else if(s[i]=='B'){e=1;}
    }
    if(b==1&&e==1){cout<<"Yes";}
    else {cout<<"No";}
    return 0;
}
