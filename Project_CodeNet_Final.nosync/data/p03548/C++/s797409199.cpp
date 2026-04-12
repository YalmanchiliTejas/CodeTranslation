#include<bits/stdc++.h>
using namespace std;
int kiage(int,int);
int main(){
	int x,y,z;
	cin>>x>>y>>z;
	cout<<(x-z)/(y+z)<<endl;
}
int kiage(int rareru,int ru){
	int anser;
	if(rareru%ru==0){
		anser=rareru/ru;
	}
	else anser=rareru/ru+1;
	return anser;
}
//長さ　幅　周りとの距離
