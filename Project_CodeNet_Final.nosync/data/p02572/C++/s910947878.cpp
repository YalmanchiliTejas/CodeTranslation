#include<bits/stdc++.h>
using namespace std;

const int MaxN=2e5;
const int MaxV=1e9;
const int M=1e9+7;

int main(){
	int N;
	long x;
	__int128 OneSum=0;
	__int128 SQRSum=0;
	
	scanf("%d\n",&N);
	while(N-->0){
		scanf("%ld",&x);
		OneSum+=x;
		SQRSum+=x*x;
	}
	__int128 ans=( (OneSum*OneSum-SQRSum)>>1 )%M;
	printf("%d\n",(int)ans);
}