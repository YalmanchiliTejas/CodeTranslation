#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstdio>

using namespace std;
int a,b,c;
int main(){
	cin>>a>>b>>c;
	if((a*100+b*10+c)%4==0)cout<<"YES";
	else cout<<"NO";
	return 0;
}