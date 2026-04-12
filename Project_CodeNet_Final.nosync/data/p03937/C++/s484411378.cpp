#include<bits/stdc++.h>
using namespace std;
int main(){
	int h,w,ans=0;
	char a;
	cin>>h>>w;
	while(cin>>a)
		if(a=='#')
			ans++;
	cout<<(ans==h+w-1?"Possible":"Impossible")<<endl;
}
