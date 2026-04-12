#include <bits/stdc++.h>
using namespace std;
    
int main(){
    
    string s;cin>>s;
  map<char,int> mp;
  
    for(char x:s){
        mp[x]++;
    }
    
     (mp['A']==3 || mp['B']==3)?cout<<"No":cout<<"Yes";
    
}