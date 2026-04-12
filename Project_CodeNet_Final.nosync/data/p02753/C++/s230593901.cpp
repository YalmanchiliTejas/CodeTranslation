#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
string s;
cin>>s;
int ca=0;
int cb=0;

for(int i=0;i<s.length();i++){
    if(s[i]=='A')
        ca++;
        else
            cb++;
}
if(ca==0||cb==0)
    cout<<"No"<<endl;
else
    cout<<"Yes"<<endl;
}
