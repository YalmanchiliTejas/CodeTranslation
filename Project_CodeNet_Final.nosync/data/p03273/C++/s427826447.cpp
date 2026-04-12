#include<bits/stdc++.h>
using namespace std;
int main() {
	int H,W;
	cin>>H>>W;
	bool flag;
	char A[100][100];
	int h=0,w=0;
	for(int i=0;i<H-h;i++){
		flag=true;
		for(int j=0;j<W;j++){
			cin>>A[i][j];
			if(A[i][j]=='#')flag=false;
		}
		if(flag==true){
			i--;
			h++;
		}
	}
	
	bool pass[100];
	for(int i=0;i<100;i++){
		pass[i]=false;
	}
	for(int i=0;i<W;i++){
		flag=true;
		for(int j=0;j<H-h;j++){
			if(A[j][i]=='#')flag=false;
		}
		if(flag==true){
			w--;
			pass[i]=true;
		}
	}
	for(int i=0;i<H-h;i++){
		for(int j=0;j<W;j++){
			if(pass[j]==false)cout<<A[i][j];
		}
		cout<<endl;
	}
}