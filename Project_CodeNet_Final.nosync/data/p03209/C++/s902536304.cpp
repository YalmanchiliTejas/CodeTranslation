#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;

long count(int N,long X);
vector<long> P,All;
long ans=0;
int main()
{
	int N,i;
	long X,ans;
	cin>>N>>X;
	P.push_back(1);
	All.push_back(1);
	for(i=1;i<=N;i++){
		All.push_back(2*All.at(i-1)+3);
		P.push_back(2*P.at(i-1)+1);
		//printf("%d %ld %ld\n",i,P.at(i),All.at(i));
	}
	ans=count(N,X);
	cout <<ans;
	return 0;
}

long count(int N,long X){
	//printf("\n%d %ld",N,X);
	if(N==0){
		return 1;
	}else if(X==1){
		return 0;
	}else if(X==((All.at(N)+1)/2)){
		return P.at(N-1)+1;
	}else if(X==All.at(N)){
		return 2*P.at(N-1)+1;
	}else if(X<((All.at(N)+1)/2)){
		return count(N-1,X-1);
	}else if(X>((All.at(N)+1)/2)){
		return (count(N-1,X-(All.at(N)+1)/2)+P.at(N-1)+1);
	}
}
