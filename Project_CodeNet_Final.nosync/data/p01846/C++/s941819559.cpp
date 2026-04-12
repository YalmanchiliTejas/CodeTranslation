#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
int main(){
	string s;
	int a,b,c,d;
	while(true){
	cin>>s;
	if(s=="#")break;
	cin>>a>>b>>c>>d;
	bool t[10][10]={0};
	int h,w,y=0,x=0;
	for(int u=0;u<s.size();u++){
		if(s[u]=='/')w=x,y++,x=0;
		if(s[u]=='b')t[y][x]=1,x++;
		if(s[u]>'0'&&s[u]<='9')x+=s[u]-'0';
	}
	h=y+1;
	t[a-1][b-1]=0,t[c-1][d-1]=1;
	for(int i=0;i<h;i++){
		if(i)cout<<"/";
		int cnt=0;
		for(int j=0;j<w;j++){
			if(t[i][j]){
				if(cnt)cout<<cnt;
				cout<<"b";
				cnt=-1;
			}
			cnt++;
		}
		if(cnt)cout<<cnt;
	}
	cout<<endl;
	}
	return 0;
}