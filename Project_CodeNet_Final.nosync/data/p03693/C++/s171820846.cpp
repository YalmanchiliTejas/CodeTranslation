#include<bits/stdc++.h> 

using namespace std; 

int main() {
	int r,g,b,d;
	cin>>r>>g>>b;
	d=d+(100*r)+(g*10)+b;
	if(d%4==0){
		cout<<"YES";
	}
	else cout<<"NO";
}