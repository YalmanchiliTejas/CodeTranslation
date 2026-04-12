#include <bits/stdc++.h>
using namespace std;
//何通りあるか答える,sは今いる場所,cは通った番号の総数
int N,M;
int A[10][10];
int rec(int s,int c){
	c = c|(1<<s) ;
	// printf("%d %d\n",s,c);
	// cout << static_cast<bitset<8> >(c) << endl;
	if(c == (1<<N)-1) return 1;
	int res = 0;
	for (int i = 0; i < N; ++i)
	{
		if(!((c>>i)&1) &&A[s][i]==1){
			res += rec(i,c);
		}
	}
	
	return res;
}
int main(){
	memset(A,0,sizeof(A));
	scanf("%d %d",&N,&M);
	for (int i = 0; i < M; ++i)
	{
		int s,e;
		scanf("%d %d",&s,&e);
		A[s-1][e-1]=1;
		A[e-1][s-1]=1;
	}
	printf("%d\n",rec(0,0));

}