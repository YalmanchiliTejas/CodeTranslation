#include<bits/stdc++.h>
#define r(i,n) for(int i=0;i<n;i++)
using namespace std;
typedef pair<int,int>P;
#define F first
#define S second
int main(){
	int a,b,c;
	cin>>a>>b>>c;
	int p=a/(b+c);
	if(a%(b+c)<c)p--;
	cout<<p<<endl;
}