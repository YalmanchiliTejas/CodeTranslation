#include<bits/stdc++.h>
using namespace std;
int main(void)
{
	int i,j,k,m,n,xx,cnt;
	char s[21];
	int player[1007];
	while(cin>>m>>n&&m&&n) {

		for(i=1;i<=m;i++) player[i]=1;
		
		cnt=m;
		xx=1;
		for(i=1;i<=n;i++) {
			cin>>s;
			if(cnt==1) continue;
			while(1) {
				if(player[xx]==1)break;
				xx++;xx=xx%(m+1);
	
			}
			if(i%15==0){
				if(strcmp(s,"FizzBuzz")!=0) player[xx]=0,cnt--;
			}
			else if(i%3==0) {
				if(strcmp(s,"Fizz")!=0) player[xx]=0,cnt--;
			}
			else if(i%5==0) {
				if(strcmp(s,"Buzz")!=0) player[xx]=0,cnt--;
			}
			else if(i!=atoi(s)) player[xx]=0,cnt--;
			xx++;xx=xx%(m+1);
		}
		xx=1;
		while(player[xx]==0) xx++,xx%(m+1);
		cout<<xx;
		for(i=xx+1;i<=m;i++) {
			if(player[i]==1) {
				cout<<" "<<i;
			}
		}
		cout<<endl;
	}
}
	