#include<bits/stdc++.h>
using namespace std;
int main(){
    
    string s; cin>>s;
  int flagA,flagB; flagB=flagA=0;
    for (auto i : s) {
        if(i=='A')
        flagA=1;
        
        if(i=='B')
        flagB=1; 

    }
    
    if(flagB && flagA)
    cout<<"Yes";
    else
      cout<<"No";
    return 0;
}