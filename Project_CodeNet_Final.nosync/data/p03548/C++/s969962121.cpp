#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

int main(){
	//input
	ll X,Y,Z; cin>>X>>Y>>Z;
	
	ll i=1;
	while(Y*i+Z*(i+1)<=X){
		i++;
	}
	cout<<i-1;
}