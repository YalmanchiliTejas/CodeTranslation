#include<bits/stdc++.h>
using namespace std;
int n;
char str[100100];
int shp[100100];
char ys[2];
int main(){
	ys[0]='S';
	ys[1]='W';
	//freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
	cin>>n;
	scanf("%s",str);
	int tmp,yg;
	for(int i=0;i<4;i++){
		shp[0]=ys[i&1];
		shp[1]=ys[(i>>1)&1];
		for(int j=1;j<n-1;j++){
			tmp=str[j];
			if(shp[j]=='W')
				tmp='o'+'x'-tmp;
			if(tmp=='o')
				shp[j+1]=shp[j-1];
			else
				shp[j+1]='W'+'S'-shp[j-1];
		}
		tmp=str[n-1];
		if(shp[n-1]=='W')
			tmp='o'+'x'-tmp;
		if(tmp=='o')
			yg=shp[n-2];
		else
			yg='W'+'S'-shp[n-2];
		if(yg!=shp[0])
			continue;
		tmp=str[0];
		if(shp[0]=='W')
			tmp='o'+'x'-tmp;
		if(tmp=='o')
			yg=shp[n-1];
		else
			yg='W'+'S'-shp[n-1];
		if(yg!=shp[1])
			continue;
		for(int i=0;i<n;i++)
			cout<<(char)(shp[i]);
		cout<<endl;
		return 0;
	}
	puts("-1");
	return 0;
}
