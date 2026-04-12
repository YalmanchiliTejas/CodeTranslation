
#include <iostream>
using namespace std;
int N,SorW[4][100010];
string S,answer[4];

string search(int x){
	for(int i=1;i<N;i++){
		if(SorW[x][i-1]==0){
			if(SorW[x][i]==0){//i-1が羊　iが羊
				if(S[i]=='o'){
					SorW[x][i+1]=0;
				}else{
					SorW[x][i+1]=1;
				}
				
			}else{//i-1が羊 iが狼
				if(S[i]=='o'){
					SorW[x][i+1]=1;
				}else{
					SorW[x][i+1]=0;
				}
			}
			
		}else{
			if(SorW[x][i]==0){//i-1が狼 iが羊
				if(S[i]=='o'){
					SorW[x][i+1]=1;
				}else{
					SorW[x][i+1]=0;
				}
			}else{//i-1が狼　iが狼
				if(S[i]=='o'){
					SorW[x][i+1]=0;
				}else{
					SorW[x][i+1]=1;
				}
			}
			
		}
	}
	int SorW__1=-1;
	
	if(SorW[x][0]==0){
		if(SorW[x][1]==0){
			if(S[0]=='o'){
				SorW__1=0;
			}else{
				SorW__1=1;
			}
		}else{
			if(S[0]=='o'){
				SorW__1=1;
			}else{
				SorW__1=0;
			}
		}
	}else{
		if(SorW[x][1]==0){
			if(S[0]=='o'){
				SorW__1=1;
			}else{
				SorW__1=0;
			}
		}else{
			if(S[0]=='o'){
				SorW__1=0;
			}else{
				SorW__1=1;
			}
		}
	}
	
	if(SorW[x][N]==SorW[x][0]&&SorW[x][N-1]==SorW__1){
		string re={};
		for(int i=0;i<N;i++){
			if(SorW[x][i]==0){
				re+="S";
			}else{
				re+="W";
			}
		}
		return re;
	}else{
		return "-1";
	}
	
}


int main(){

	cin >> N >> S;
	
	for(int i=0;i<4;i++){
		answer[i]={};
		for(int j=0;j<100010;j++){
			SorW[i][j]=-1;
		}
	}
	
	SorW[0][0]=0;SorW[0][1]=0;SorW[1][0]=0;SorW[1][1]=1;
	SorW[2][0]=1;SorW[2][1]=0;SorW[3][0]=1;SorW[3][1]=1;
	
	
	string Answer="";
	
	for(int i=0;i<4;i++){
		answer[i]=search(i);
		if(answer[i].size()>Answer.size()){
			Answer=answer[i];
		}
	}
	
	cout << Answer << endl;
	
	return 0;
}
