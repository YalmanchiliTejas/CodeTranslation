#include<bits/stdc++.h>
using namespace std;
int main(void)
{
	char name[6]={"ABCDE"};
	int i,j,k,a,b,sum,mx,cnt;
	while(1) {
		cin>>a>>b;
		if(!a&&!b) break;
		cnt=0;
		mx=a+b;
		for(i=1;i<5;i++) {
			cin>>a>>b;
			if(mx<a+b) mx=a+b,cnt=i;
		}
		cout<<name[cnt]<<" "<<mx<<endl;
	}
}