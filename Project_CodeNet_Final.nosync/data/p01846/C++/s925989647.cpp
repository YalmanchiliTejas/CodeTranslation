#include<bits/stdc++.h>
using namespace std;
int main(){
	string s;
	
	while(	cin>>s){
		if(s=="#")break;
		int a,b,c,d;
		cin>>a>>b>>c>>d;
		a--,b--,c--,d--;
		char ma[10][10];
		int y=0,x=0;
		for(int i=0;i<s.size();i++){
			if(s[i]=='b'){
				ma[y][x++]='b';
			}else if(s[i]=='/'){
				y++;
				x=0;
			}else{
				int k=s[i]-'0';
				for(int j=0;j<k;j++)
					ma[y][x++]='.';
			}
		}
		y++;
		ma[a][b]='.';
		ma[c][d]='b';
		string t;
		for(int i=0;i<y;i++){
			for(int j=0;j<x;j++){
				t+=ma[i][j];
			}
			if(i!=y-1)t+='/';
		}
		//cout<<t<<endl;
		for(int i=0;i<t.size();i++){
			if(t[i]=='b'||t[i]=='/')cout<<t[i];
			else {
				int sum=1;
				while(1){
					if(i>=t.size()-1)break;
					if(t[i+1]!='.')break;
					sum++;
					i++;
				}
				cout<<sum;
			}
		}
		cout<<endl;
	}
	return 0;
}

