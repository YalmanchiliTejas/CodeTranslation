#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

int main(){
	int n,k;
	string s;
	cin>>n>>s>>k;
	char t;
	t=s[k-1];
	for(int i=0;i<n;i++){
		if(s[i]==t){
			cout<<t;
		}else{
			cout<<'*';
		}
	}
	cout<<endl;
	return 0;
}