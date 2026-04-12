#include<cstdio>
#include<cstring>
#include<algorithm>
#include<functional>
#include<vector>
#include<stack>
#include<queue>
#include<iostream>
using namespace std;
int main(void)
{
	int sum=0,mx=-1,ss,s,pl;
	char pp[5]={'A','B','C','D','E'};
	while(1) {
		cin>>s>>ss;
		mx=s+ss;pl=0;
		if(s==0 && ss==0) break;
		for(int i=1;i<5;i++) {
			sum=0;
			cin>>s>>ss;
			sum=s+ss;
			if(mx<sum) {mx=sum;pl=i;}
		}
		cout<<pp[pl]<<" "<<mx<<endl;
	}
}
	