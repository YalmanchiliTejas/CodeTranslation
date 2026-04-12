#include<bits/stdc++.h>
using namespace std;
int n;
string str,res;
map<char,char> opp;
int main(){
	//freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
	opp['S']='W';
	opp['W']='S';
	cin>>n>>str;
	for(int i=0;i<n;i++)
		res+="?";
	res[0]='S';
	res[n-1]='S';
	while(1){
		bool ok=true;
		for(int i=0;i<n;i++){
			if(str[i]=='o'&&res[i]=='S'||str[i]=='x'&&res[i]=='W'){
				if(res[(i+1)%n]!=res[(i-1+n)%n]&&res[(i+1)%n]!='?')
				{
					ok=false;
					break;
				}
				res[(i+1)%n]=res[(i-1+n)%n];
			}
			else{
				if(res[(i+1)%n]==res[(i-1+n)%n]&&res[(i+1)%n]!='?')
				{
					ok=false;
					break;
				}
				res[(i+1)%n]=opp[res[(i-1+n)%n]];
			}
		}
		if(ok){
			cout<<res<<endl;
			return 0;
		}
		for(int i=1;i<n-1;i++)
			res[i]='?';
		if(res[0]=='S'&&res[n-1]=='S')
			res[n-1]='W';
		else if(res[0]=='S'&&res[n-1]=='W')
			res[0]='W',res[n-1]='S';
		else if(res[0]=='W'&&res[n-1]=='S')
			res[n-1]='W';
		else
			break;
	}
	cout<<-1<<endl; 
	return 0;
}
//OWN