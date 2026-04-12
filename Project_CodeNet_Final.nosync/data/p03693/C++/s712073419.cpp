#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstdio>
#include<string>
#include<vector>
#include<set>
#include<cctype>
using namespace std;

int main(void){
	ios::sync_with_stdio(false); cin.tie(0);
	
	int a,b,c;
	cin>>a>>b>>c;
	if((a*100+b*10+c)%4==0)cout<<"YES"<<endl;
	else cout<<"NO"<<endl;
	
	
	return 0;
}