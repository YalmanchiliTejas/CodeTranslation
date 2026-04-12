#include<algorithm>
#include <bits/stdc++.h>
#include <math.h>
#include <queue>
using namespace std;
int main(void){
	int r,g,b,ans;
	cin>>r>>g>>b;
	ans=r*100+g*10+b;
	if(ans%4==0) cout<<"YES\n";
	else cout<<"NO\n";
	return 0;
}