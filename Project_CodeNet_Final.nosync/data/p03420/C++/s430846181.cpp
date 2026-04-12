#include<bits/stdc++.h>
using namespace std;
int N;
int calc(int from, int to){
	if(from == 0)from = 1;
	if(from > N)return 0;
	if(to > N)to = N;
	if(from > to)return 0;
	return to - from + 1;
}
int main(){
	int K;
	scanf("%d%d",&N,&K);
	long long int res = 0;
	for(int B = K+1; B <= N; B++)
		for(int C = 0; B * C <= N; C++)
			res += calc(B*C+K, B*C+B-1);
	printf("%lld\n",res);
	return 0;
}
