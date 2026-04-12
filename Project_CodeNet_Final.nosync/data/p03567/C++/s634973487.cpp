#include<cstdio>
#include<cmath>
#include<cstring>
#include<cstdlib>
#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
	char str[10];
	int n,vis=0;
	cin>>str;
	n=strlen(str);
	for(int i=0;i<n;i++){
		if(str[i]=='A' && str[i+1]=='C'){
		   vis=1;
		   break;
		}
	}
	if(vis)
       cout<<"Yes"<<endl;
    else
       cout<<"No"<<endl;
	return 0;
}