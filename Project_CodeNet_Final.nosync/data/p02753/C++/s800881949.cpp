#include<bits/stdc++.h>
using namespace std;
int main(){
    string s;
    int i;
    cin>>s;
    int x=0,y=0;
    for(i=0;s[i]!='\0';i++){
        if(s[i]=='A')
        x++;
        if(s[i]=='B')
        y++;
    }
    if(x==3 || y==3)
    cout<<"No"<<endl;
    else
    {
        cout<<"Yes"<<endl;
    }
    
}