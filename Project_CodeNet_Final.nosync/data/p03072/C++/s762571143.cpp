#include<iostream>
using namespace std;

int main(){
	int N;
	cin>>N;
	int ans=1;
	int h;
	cin>>h;
	int tmp;
	for(int i=1;i<N;++i){
		cin>>tmp;
		if(tmp<h){
			continue;
		}
		else{
			ans++;
			h=tmp;
		}
	}
	cout<<ans<<endl;
}
