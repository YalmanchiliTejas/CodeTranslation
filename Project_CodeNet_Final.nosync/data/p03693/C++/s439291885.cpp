#include<iostream>
#include<algorithm>
using namespace std;

int main(){

	int r,g,b,a,bit;

	cin >>r>>g>>b;

	a=100*r+g*10+b;

	if(a%4 ==0)cout <<"YES" <<endl;

	else cout <<"NO" <<endl;
}
