#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,m;
	cin>>n>>m;
	char rem[n][m+1];
	for (int i=0;i<n;i++){
		scanf("%s",rem[i]);
	}
	int dc[m];
	int dr[n];
	for (int i=0;i<n;i++){
		int good=0;
		for (int j=0;j<m;j++){
			if (rem[i][j]!='.'){
				good=1;
				break;
			}
		}
		dr[i]=good;
	}
	for (int i=0;i<m;i++){
		int good=0;
		for (int j=0;j<n;j++){
			if (rem[j][i]!='.'){
				good=1;
				break;
			}
		}
		dc[i]=good;
	}
	for (int i=0;i<n;i++){
		for (int j=0;j<m&&dr[i];j++){
			if (dc[j])printf ("%c",rem[i][j]);
		}
		if (dr[i])printf ("\n");
	}
}