#include<bits/stdc++.h>
typedef long long ll;
using namespace std;

const int N = 3003;
int n , a[N] , ti , vis[N][N][3]; 
ll mem[N][N][3];

ll dp(int i , int j , int pl){
	if(i>j) return 0;
	ll &ret = mem[i][j][pl];
	int &vs = vis[i][j][pl];
	if( vs == ti ) return ret;
	vs = ti;
	return ret = max( 
			a[i] + dp(i+1 , j , (pl+1)%2)*(pl? -1 : -1),
			a[j] + dp(i , j-1 , (pl+1)%2)*(pl? -1 : -1)
			);
}

int main(){
	scanf("%d" , &n);
	for(int i=0 ; i<n ; i++) scanf("%d" , a + i);
	ti++;
	printf("%lld" , dp(0 , n-1 , 1));
}
