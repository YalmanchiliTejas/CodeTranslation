#include<iostream>
#include<algorithm>

using namespace std;
double sikin_tan(double,int,int,double);
double sikin_huku(double,int,int,double);

int main(){
	int m;
	cin>>m;
	int n,nensuu,tan_huku,tesuu;
	double money,kinri,maxi=0.0;
	for(int i=0;i<m;i++){
		cin>>money;
		cin>>nensuu;
		cin>>n;
		for(int j=0;j<n;j++){
			cin>>tan_huku>>kinri>>tesuu;	//0のとき単利、1のとき複利
			if(tan_huku==0)
				maxi=max(maxi,sikin_tan(money,nensuu,tesuu,kinri));
			else if(tan_huku==1)
				maxi=max(maxi,sikin_huku(money,nensuu,tesuu,kinri));
		}
		cout<<(int)maxi<<endl;
		maxi=0;
	}
}
double sikin_tan(double money,int nensu,int tesu,double kinri){
	int risi=0;
	for(int i=0;i<nensu;i++){
		risi+=money*kinri;
		money-=(double)tesu;
	}
	return money+risi;
}
double sikin_huku(double money,int nensu,int tesu,double kinri){
	int risi=0;
	for(int i=0;i<nensu;i++){
		risi=money*kinri;
		money+=risi;
		money-=(double)tesu;
	}
	return money;
}