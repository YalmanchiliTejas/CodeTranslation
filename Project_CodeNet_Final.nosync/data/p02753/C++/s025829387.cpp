#include <bits/stdc++.h>
using namespace std;

int n,i,arr[3];
string s;

int main(){
	cin>>s;
	n=s.length();
	for(i = 1;i<=n;i++){
		if(s.substr(i - 1,1) == "A"){
			arr[1]++;
		}
		else{
			arr[2]++;
		}
	}
	if(arr[1] == 0 || arr[2] == 0){
		cout<<"No"<<endl;
		
	}
	else{
		cout<<"Yes"<<endl;
	}
}