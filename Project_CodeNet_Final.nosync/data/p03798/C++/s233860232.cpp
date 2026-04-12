#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;
	string s;
	cin>>n>>s;
	string ans;
	string cand[4]={"SS","SW","WS","WW"};
	for(int i=0;i<4;i++)
	{
		for(int j=2;j<=n;j++)
		{
			if(cand[i][j-1]=='S'&& s[j-1]=='o'){
				if(cand[i][j-2]=='S')
				   cand[i]+='S';
				else 
				   cand[i]+='W';
			}
			else  if(cand[i][j-1]=='S'&& s[j-1]=='x'){
				if(cand[i][j-2]=='S')
				   cand[i]+='W';
				else 
				   cand[i]+='S';
			}
			else  if(cand[i][j-1]=='W'&& s[j-1]=='o'){
				if(cand[i][j-2]=='S')
				   cand[i]+='W';
				else 
				   cand[i]+='S';
			}
			else  if(cand[i][j-1]=='W'&& s[j-1]=='x'){
				if(cand[i][j-2]=='S')
				   cand[i]+='S';
				else 
				   cand[i]+='W';
			}
		}
		if(cand[i][0]!=cand[i][n])continue;
		if((cand[i][0]=='S'&& s[0]=='o'&& cand[i][1]==cand[i][n-1])||
		  (cand[i][0]=='S'&& s[0]=='x'&& cand[i][1]!=cand[i][n-1])||
		  (cand[i][0]=='W'&& s[0]=='o'&& cand[i][1]!=cand[i][n-1])||
		  (cand[i][0]=='W'&& s[0]=='x'&& cand[i][1]==cand[i][n-1])){
		  	ans=cand[i].substr(0,n);
		  	break;
		  }	
	} 
	if(ans.size()>0)cout<<ans;
	else cout<<-1;  
	return 0;
} 