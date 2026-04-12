#include<bits/stdc++.h>
using namespace std;
int main(){
string s;cin>>s;
bool b = 0,c = 0,d = 0;
if(s.length()==3){
    char x[4];
    strcpy(x,s.c_str());
    for(int i=0;i<s.length();i++){
        if(int(x[i])>=65||int(x[i])<=90)
            b = 0;
        else
            b = 1;
    }
    if(b==0)
    for(int i=0;i<s.length();i++){
            if(x[i]=='A')
                c = 1;
            else
                d = 1;
}
if(c==1&&d==1)
    cout<<"Yes"<<endl;
else
    cout<<"No"<<endl;}
return 0;}
