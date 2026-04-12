#include<bits/stdc++.h>
using namespace std;
int n;
bool x[100100];
char str[100100]; 
int s[100100];
int main(){
	//freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
	cin>>n;
	scanf("%s",str);
	for(int i=0;i<n;i++)
		x[i+1]=(str[i]=='x');
	x[n+1]=x[1];
	for(int mask=0;mask<8;mask++){
		s[0]=mask&1;
		s[1]=(mask>>1)&1;
		s[2]=(mask>>2)&1;
		for(int j=2;j<=n+1;j++)
			s[j+1]=(s[j-2]^x[j]);
		if(s[0]^s[n]^s[1]^s[n+1]||s[1]^s[n+1]^s[2]^s[n+2])
			continue;
		for(int i=1;i<=n;i++){
			if(s[i]^s[i-1])
				cout<<'W';
			else
				cout<<'S';
		}
		return  0;
	}
	cout<<-1;
	return 0;
}
