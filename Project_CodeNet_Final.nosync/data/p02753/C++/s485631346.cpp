#include <bits/stdc++.h>
using namespace std;
 
int main() {

  ios_base::sync_with_stdio(false); 
    cin.tie(NULL);    
  
	 long long n,i,j,k,sum=0,ans=0,count=0,c1=0,c2=0,x=-1,p,mn;
	 string s;
	 cin>>s;
	 for(i=0;i<s.length();i++)
	 {
	     if(s[i]=='A')
	     count++;
	     
	 }
	 if(count==0 || count==3)
	 cout<<"No";
	 else
	 cout<<"Yes";
}