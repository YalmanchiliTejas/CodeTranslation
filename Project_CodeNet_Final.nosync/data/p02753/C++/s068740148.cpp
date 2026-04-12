#include<bits/stdc++.h>
using namespace std;
#define ifor(i,n) for(i=0;i<n;i++)
#define ll long long
int main()
{
     ios_base::sync_with_stdio(false);
     cin.tie(NULL);
     ll int i,n,t,p=INT_MAX,j=0,x,a=0,b,l=0,r=0;
     string s,m;
     set<char>se;
     cin>>s;
     for(i=0;i<s.size();i++){
        se.insert(s[i]);
     }
     if(se.size()==2){
        cout<<"Yes"<<endl;
     }
     else{
        cout<<"No"<<endl;
     }


     return EXIT_SUCCESS;
}


