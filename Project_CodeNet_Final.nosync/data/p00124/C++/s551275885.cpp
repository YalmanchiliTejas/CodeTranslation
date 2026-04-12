#include<cstdio>
#include<cstring>
#include<algorithm>
#include<functional>
#include<cstdlib>
#include<iostream>
using namespace std;
int main(void)
{
	int i,j,k,x,n,setcnt,ff;
	int win,lose,drow,mx=-1;
	char kuni[11][21];
	int tokuten[11];
	char team[21];
	setcnt=0;
	while(1) {
		cin>>n;
		if(n==0) break;
		else if(setcnt!=0)cout<<endl;
		for(i=0;i<n;i++) {
			cin>>kuni[i]>>win>>lose>>drow;
			tokuten[i]=win*3+drow;
		}
		for(i=0;i<n;i++) {
			for(j=0;j<n;j++) {
				if(mx<tokuten[j] && tokuten[j]!=-1) {
					mx=tokuten[j];
					ff=j;
					strcpy(team,kuni[j]);
				}
			}
			cout<<team<<","<<mx<<endl;
			tokuten[ff]=-1;mx=-1;
		}
		setcnt++;
	}
	return 0;
}