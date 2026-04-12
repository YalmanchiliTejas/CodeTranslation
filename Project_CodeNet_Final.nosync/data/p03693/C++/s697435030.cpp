#include "bits/stdc++.h"
using namespace std;

int r,g,b,num=0;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin>>r>>g>>b;
	num=r*100+g*10+b;
	if(num%4==0)
		cout<<"YES";
	else
		cout<<"NO";
	return 0;
}