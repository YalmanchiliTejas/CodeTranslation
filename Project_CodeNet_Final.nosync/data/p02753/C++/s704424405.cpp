#include<bits/stdc++.h>
#define crap ios_base::sync_with_stdio(0);cin.tie(0)
#define ll long long
#define pb push_back
#define ff first
#define ss second
#define endl "\n"
#define int ll

using namespace std;


int32_t main()
{
   
   
    crap;
    
     string s; 
     cin>>s;
     int a=0,b=0;
     for(int i=0;i<3;i++){
      if(s[i]=='A' ){
        a = 1;
      }
      else if(s[i]=='B')
        b = 1;
     }
     if(a==1 && b==1) cout<<"Yes"<<endl;
     else cout<<"No"<<endl;

}