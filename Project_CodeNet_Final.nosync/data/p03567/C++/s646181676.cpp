#include<cstring>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<iostream>
using namespace std;
char s[10];
int main(){
	cin>>s;
	int n = strlen(s);
	for(int i = 0;i < n;i++){
		if(s[i] == 'A' && s[i + 1] == 'C') 
		{
			cout<<"Yes"<<endl;
			return 0;
		}
	}
	cout<<"No"<<endl;
	return 0;
}