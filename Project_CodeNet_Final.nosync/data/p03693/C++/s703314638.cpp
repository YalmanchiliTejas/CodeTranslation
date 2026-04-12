#include"bits/stdc++.h"
using namespace std;
int main(){
	string x,temp;
	for(int i=0;i!=3;++i){
		cin>>temp;
		x+=temp;
	}
	int y=stoi(x);
	cout<<((y%4) ? "NO":"YES");
}