#include<bits/stdc++.h>
using namespace std;


int main()
{
	int n,k;  
	char s[20];
	 
	 cin>>n>>s>>k;
	 k--;
	 for(int i=0;i<n;i++){
		 
		 if(s[i]==s[k]){
			 cout<<s[i];
	      }
	      else {
			  cout<<"*";
	      
	 }
	 	
   }

}
