#include<iostream>
using namespace std;

int comp(int m,int y,int w,double in,int ch){
	for(int i=0;i<y;i++){
		m = m * (1.0 + in) - ch;
	}
	return m;
}
int simp(int m,int y,int w,double in,int ch){
	int sum = 0;
	for(int i=0;i<y;i++){
		sum += m * in;
		m -= ch;
	}
	return sum + m;
}
int main(){
	int d,m,y,n;//f[^Zbg,ú^pà,^pN,^píÞ
	int w,ch;// {¡|P},è¿
	double in;//N¦
	cin>>d;
	//for(;m>0;--m)
	for(int i=0;i<d;i++){
		int maxM=0;
		cin>>m>>y>>n;
		for(int j=0;j<n;j++){
			cin>>w>>in>>ch;
			if(w)maxM=max(maxM,comp(m,y,w,in,ch));			else maxM=max(maxM,simp(m,y,w,in,ch));
		}
		cout<<maxM<<endl;

	}
	return 0;
}