#include<iostream>
#include<vector>
using namespace std;
int main(){
	int n;
	cin >> n;
	string s;
	cin >> s;
	char sw[2]={'S','W'};
	vector<vector<char>> c(4,vector<char>(n,'A'));
	for(int i=0;i<2;i++){
		for(int j=i;j<i+2;j++){
			c[i+j][0]=sw[i];
			if(sw[i]=='S'&&s[0]=='o' || sw[i]=='W'&&s[0]=='x'){
				if(j==i){
					c[i+j][1]='S';
					c[i+j][n-1]='S';
				}else if(j==i+1){
					c[i+j][1]='W';
					c[i+j][n-1]='W';
				}
			}else{
				if(j==i){
					c[i+j][1]='S';
					c[i+j][n-1]='W';
				}else if(j==i+1){
					c[i+j][1]='W';
					c[i+j][n-1]='S';
				}
			}
		}
	}
	bool ans=false;
	int ansk;
	for(int k=0;k<4;k++){
		bool flag=true;
		for(int i=1;i<n;i++){
			int next;
			if(i==n-1) next=0;
			else next=i+1;
			if(s[i]=='o'){
				if(c[k][i]=='S'){
					if(c[k][next]=='A') c[k][next]=c[k][i-1];
					else if(c[k][next]!=c[k][i-1]) flag=false;
				}else{
					if(c[k][next]=='A') c[k][next]=(c[k][i-1]=='S'?'W':'S');
					else if(c[k][next]==c[k][i-1]) flag=false;
				}
			}else{
				if(c[k][i]=='W'){
					if(c[k][next]=='A') c[k][next]=c[k][i-1];
					else if(c[k][next]!=c[k][i-1]) flag=false;
				}else{
					if(c[k][next]=='A') c[k][next]=(c[k][i-1]=='S'?'W':'S');
					else if(c[k][next]==c[k][i-1]) flag=false;
				}
			}
			if(!flag) break;
		}
		if(flag) {
			ans=true;
			ansk=k;
			break;
		}
	}
	if(ans){
		for(int i=0;i<n;i++) cout << c[ansk][i];
		cout << endl;
	}else
		cout << -1 << endl;
	return 0;
}
