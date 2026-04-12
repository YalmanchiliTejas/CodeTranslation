#include <bits/stdc++.h>
using namespace std;
int main(){
	int cnt1=0,cnt2=0;
	string a;
	cin>>a;
	for(int i=0;i<3;i++){
		if(a[i]=='A')cnt1++;
		else cnt2++;
	}
	if((!cnt1)||(!cnt2))cout<<"No";
	else cout<<"Yes";
	return 0;
}