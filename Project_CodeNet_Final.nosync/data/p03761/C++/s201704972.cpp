#include<bits/stdc++.h>                          
using namespace std;                          
const int MAX=0x3f3f3f3f;
int ch[200],ans[200];                       
int main(){
	int n;
	cin>>n;      
	string s; 
	memset(ans,MAX,sizeof(ans));
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