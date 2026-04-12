#include<iostream>
using namespace std;
int main(){
	int h,w;
	cin>>h>>w;
	char c;
	int cnt=0;
	for(int i=0;i<h*w;++i){
		cin>>c;
		cnt+=c=='#';
	}
	cout<<(cnt==h+w-1?"P":"Imp")<<"ossible"<<endl;
	return 0;
}