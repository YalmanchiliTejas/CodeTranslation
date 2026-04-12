#include<bits/stdc++.h>
using namespace std;

int main(){
 int c=0;
 string s;
 cin>>s;
 
 for(int i=0;i<s.size();i++)if(s[i]=='A')c++;
 
 if(c>0&&c<s.size())cout<<"Yes";
 
 else cout<<"No";
 
}
    
  
  