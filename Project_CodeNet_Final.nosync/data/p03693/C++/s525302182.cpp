#include<iostream>
#include<string>
#include<cstdlib>
#include<algorithm>
#include<cctype>

using namespace std;


int main(){
int a,b,c;
	
	cin>>a>>b>>c;
	
	if((a*100+b*10+c)%4){//余りがあると1が建つのでnoが出力
		cout<<"NO"<<endl;
	}else cout<<"YES"<<endl;
	return 0;

}