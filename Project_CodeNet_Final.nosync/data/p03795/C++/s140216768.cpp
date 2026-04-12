#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
int main(){
	int n;
	cin>>n;
	int ans=n*800;
	ans=ans-n/15*200;
	cout<<ans<<endl;
	return 0;
}