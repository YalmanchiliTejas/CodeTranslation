#include<bits/stdc++.h>
using namespace std;
 
int main(){
	 int h,w;
	 cin>>h>>w;
	 char b[100][100];
	 vector<bool> col(h,false),row(w,false);

	 for (int i = 0; i < h; i++){
	 	for (int j = 0; j < w; j++){
	 		cin>>b[i][j];
	 		if(b[i][j]=='#'){
	 			row[i]=1;
	 			col[j]=1;
	 		}
	 	}
	 }

	 for (int i = 0; i < h; i++){
	 	if(row[i]){
	 		for (int j = 0; j < w; j++){
	 			if(col[j]) cout<<b[i][j];
	 		}
	 		cout<<endl;
	 	}
	 }
}

