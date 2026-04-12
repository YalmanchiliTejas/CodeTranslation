#include<iostream>
#include<iomanip>
#include<cstdio>
#include<bitset>
#include<map>
#include<math.h>
#include<cstring>
#include<string>
#include<queue>
#include<algorithm>
typedef long long LL; 
using namespace std;
const int maxn=10002;
const int INF=999999999;
int n;
int main(){
	int a,b,c,x,y;
	cin>>a>>b>>c>>x>>y;
	int same=x>y?y:x;
	int partSame=0;
	if(a+b>2*c){
		partSame=2*c*same;
	}else{
		partSame=(a+b)*same;
	}
	int rest,restPart;
	if(x>y){
		rest=x-same;
		if(2*c<a) restPart=rest*c*2;
		else restPart=rest*a;
	}else{
		rest=y-same;
		if(2*c<b) restPart=rest*c*2;
		else restPart=rest*b;
	}
	cout<<partSame+restPart<<endl;
	return 0;
}            