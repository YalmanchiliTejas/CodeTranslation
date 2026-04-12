#include<iostream>
#include<string>
using namespace std;

int main(){
	int N;
	char str[100005],ans[100005];
	char animal1[4]={'S','S','W','W'},animal2[4]={'S','W','S','W'};
	cin>>N;
	for(int i=0;i<N;++i) cin>>str[i];
	bool b=false;
	for(int i=0;i<4;++i){
		ans[0]=animal1[i];
		ans[1]=animal2[i];
		for(int j=1;j<N-1;++j){
			if(ans[j]=='S'){
				if(str[j]=='o') ans[j+1]=ans[j-1];
				if(str[j]=='x'){
					if(ans[j-1]=='S') ans[j+1]='W';
					if(ans[j-1]=='W') ans[j+1]='S';
				}
			}
			if(ans[j]=='W'){
				if(str[j]=='x') ans[j+1]=ans[j-1];
				if(str[j]=='o'){
					if(ans[j-1]=='S') ans[j+1]='W';
					if(ans[j-1]=='W') ans[j+1]='S';
				}
			}
		}
		b=false;
		if(ans[N-1]=='S'){
			if(str[N-1]=='o'&&ans[N-2]!=ans[0])b=true;
			if(str[N-1]=='x'&&ans[N-2]==ans[0])b=true;
		}
		if(ans[N-1]=='W'){
			if(str[N-1]=='o'&&ans[N-2]==ans[0])b=true;
			if(str[N-1]=='x'&&ans[N-2]!=ans[0])b=true;
		}
		if(ans[0]=='S'){
			if(str[0]=='o'&&ans[N-1]!=ans[1])b=true;
			if(str[0]=='x'&&ans[N-1]==ans[1])b=true;
		}
		if(ans[0]=='W'){
			if(str[0]=='o'&&ans[N-1]==ans[1])b=true;
			if(str[0]=='x'&&ans[N-1]!=ans[1])b=true;
		}
		if(!b){
			for(int k=0;k<N;++k){
				cout<<ans[k];
			}
			cout<<endl;
			break;
		}
	}
	if(b) cout<<-1<<endl;
}
