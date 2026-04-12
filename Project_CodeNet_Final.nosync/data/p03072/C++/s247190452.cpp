#include <bits/stdc++.h>
using namespace std;
int main(){
	int cnt=0;
	int max=0;
	int n;
	cin>>n;
	while(n--){
		int x;
		cin>>x;
		if(x>=max){
			max=x;
			cnt++;
		}
	}
	cout<<cnt<<endl;
}