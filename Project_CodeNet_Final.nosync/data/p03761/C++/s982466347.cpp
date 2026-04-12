#include<bits/stdc++.h>                          
using namespace std;                          
int t[200],ans[200],ch[200];
                     
int main(){
	int n;
	cin>>n;      
	string s; 
		for(int i=0;i<200;i++)
	{		
	   ans[i]=0x3f3f3f3f;
    }   
	
	for(int i=0;i<n;i++)
	{		
	    cin>>s; 
	    memset(ch,0,sizeof(ch));
		       
		for(int i=0;i<s.size();i++)
		{
		    ch[s[i]]++;	
		}  
		for(int i='a';i<='z';i++)
		{
	    	ans[i]=min(ans[i],ch[i]);			
		}
    }   
	for(int i='a';i<='z';i++)
	{
		for(int j=0;j<ans[i];j++)
		{
			cout<<(char)i;
		}
	}    
	return 0;
}                                               