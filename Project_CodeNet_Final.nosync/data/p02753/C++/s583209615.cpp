#include<bits/stdc++.h>
 using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0); 
#define FOR(i,a,n) for(int i = (a); i<(n); ++i) 
#define endl "\n"
 


int main()
{     
     IOS;
      
     string s;
     cin>>s;
    set<char> st;
      
      FOR(i,0,3)  st.insert(s[i]);
      
    if(st.size()==2)  cout<<"Yes";
     else  cout<<"No";
  
        
    
      return 0;
} 

