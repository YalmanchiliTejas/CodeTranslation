#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<stdlib.h>
#include<math.h>
typedef long long ll;
using namespace std;
int main(){
	
	ll r,b,g;
	cin>>r>>b>>g;
	
	if((b*10 + g)%4 == 0){
		
		cout << "YES";
		
	}else{
		
		cout << "NO";
	}
	
	return 0;
	
}