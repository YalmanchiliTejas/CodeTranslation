#include <bits/stdc++.h>
using namespace std;
int main(){
	int a;
	cin>>a;
	int b[a],cnt=a;
	for(int i=0;i<a;i++){
		cin>>b[i];
	}
	for(int i=a-1;i>=0;i--){
		for(int j=0;j<i;j++){
			if(b[i]<b[j]){
				cnt--;
				break;
			}
		}
	}
	cout<<cnt;
}
//FELAROSSO 2019