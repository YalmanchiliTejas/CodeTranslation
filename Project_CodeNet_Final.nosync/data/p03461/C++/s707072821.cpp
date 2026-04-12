#include<bits/stdc++.h>
using namespace std;

int d[11][11];
int f[101][101];

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int A,B;
	cin>>A>>B;
	for(int i=1;i<=A;i++)
		for(int j=1;j<=B;j++)
			cin>>d[i][j];
	for(int i=1;i<=A;i++)
		for(int j=1;j<=B;j++)
			for(int a=0;a<=100;a++)
				for(int b=0;b<=100;b++)
					f[a][b]=max(d[i][j]-i*a-j*b,f[a][b]);
	for(int i=1;i<=A;i++)
		for(int j=1;j<=B;j++){
			bool sw=false;
			for(int a=0;a<=100;a++)
				for(int b=0;b<=100;b++)
					if(f[a][b]+a*i+b*j==d[i][j])
						sw=true;
			if(!sw){
				cout<<"Impossible"<<endl;
				return 0;
			}
		}
	cout<<"Possible"<<endl;
	cout<<202<<' '<<101*101+200<<endl;
	cout<<201<<' '<<1<<" X\n";
	for(int i=1;i<100;i++)
		cout<<i<<' '<<i+1<<" X\n";
	for(int i=101;i<200;i++)
		cout<<i<<' '<<i+1<<" Y\n";
	cout<<200<<' '<<202<<" Y\n";
	for(int i=0;i<=100;i++)
		for(int j=0;j<=100;j++){
			if(i==0)
				cout<<201;
			else
				cout<<i;
			cout<<' ';
			if(j==0)
				cout<<202<<' ';
			else
				cout<<201-j<<' ';
			cout<<f[i][j]<<'\n';
		}
	cout<<201<<' '<<202<<endl;
}
