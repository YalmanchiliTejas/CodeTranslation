#include<iostream>
using namespace std ;
int main()
{
	int m,n;
	cin >> m >> n;
	char a[110][110] ;
	for(int i=0;i<m;i++)
		for(int j=0;j<n;j++)
			cin >> a[i][j];
			
	int c=0,s[110];
	for(int i=0;i<m;i++){
		int flag=0;
		for(int j=0;j<n;j++)
			if(a[i][j]=='.') flag++;
		if(flag==n) {
			for(int k=0;k<n;k++)
				{a[i][k]='1' ;s[i]=1;}
		}
		else s[i]=0;
	}
	int d=0,f[110];
	for(int i=0;i<n;i++){
		int flag=0;
		for(int j=0;j<m;j++)
		if(a[j][i]=='.'||a[j][i]=='1') flag++;
		if(flag==m) {
			for(int k=0;k<m;k++)
				a[k][i]='1' ;
		}
	}
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++)
			if(a[i][j]!='1' ) cout << a[i][j] ;
		if(s[i]!=1) cout << endl ;
	}
	return 0;
}