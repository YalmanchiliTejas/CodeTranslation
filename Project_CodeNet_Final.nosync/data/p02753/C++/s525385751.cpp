#include <iostream>
#include <string>

using namespace std;

int main(){
	
	cin.tie(0); ios_base::sync_with_stdio(0);
	string en;
	cin>>en;
	for(int i=0;i<3;i++)for(int j=i+1;j<3;j++)if(en[i]!=en[j]){
		cout<<"Yes\n";
		return 0;
	}
	cout<<"No\n";
	
	return 0;
}