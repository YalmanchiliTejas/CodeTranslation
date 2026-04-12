#include <iostream>
#include<algorithm>
#include<string>
#include<map>
#include<iomanip>
#include<vector>
#include<cmath>
#define mod 1000000007
#define pa(a,b) make_pair(a,b)
#define LL  long long int
using namespace std;
int buf[50];
inline void write(int x)
{
	int p=0;
	do{
		buf[p++]=x%10;
		x/=10;
	}while(x>0);
	for(int i=p-1;i>=0;i--)putchar('0'+buf[i]);
}
long long int read_int(){
	char r;
	bool start=false,neg=false;
	long long int ret=0;
	while(true){
		r=getchar();
		if((r-'0'<0 || r-'0'>9) && r!='-' && !start){
			continue;
		}
		if((r-'0'<0 || r-'0'>9) && r!='-' && start){
			break;
		}
		if(start)ret*=10;
		start=true;
		if(r=='-')neg=true;
		else ret+=r-'0';
	}
	if(!neg)
		return ret;
	else
		return -ret;
}
int main()
{
    int r,g,b; cin>>r>>g>>b; int num=r*100+g*10+b;
    num%4==0 ? cout<<"YES" : cout<<"NO";
}
