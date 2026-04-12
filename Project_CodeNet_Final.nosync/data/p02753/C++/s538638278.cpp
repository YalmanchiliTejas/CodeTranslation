#include <bits/stdc++.h> 
using namespace std;

int main() {
string s;
int res=0,count=0;
cin>>s;
for(int i=0;i<s.size();i++){
    if(s[i]=='A'){
        count++;
    }
    if(s[i]=='B'){
        res++;
    }
}
if(count==s.size() || res==s.size()){
    cout<<"No"<<endl;
}
else
cout<<"Yes"<<endl;
return 0;
}