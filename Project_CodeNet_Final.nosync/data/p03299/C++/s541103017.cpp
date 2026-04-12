#include <bits/stdc++.h>
using namespace std;
#define iinf 2000000000
#define linf 1000000000000000000LL
#define ulinf 10000000000000000000ull
#define MOD1 1000000007LL
#define mpr make_pair
typedef long long LL;
typedef unsigned long long ULL;
typedef unsigned long UL;
typedef unsigned short US;
typedef pair < int , int > pii;
clock_t __stt;
inline void TStart(){__stt=clock();}
inline void TReport(){printf("\nTaken Time : %.3lf sec\n",(double)(clock()-__stt)/CLOCKS_PER_SEC);}
template < typename T > T MIN(T a,T b){return a<b?a:b;}
template < typename T > T MAX(T a,T b){return a>b?a:b;}
template < typename T > T ABS(T a){return a>0?a:(-a);}
template < typename T > void UMIN(T &a,T b){if(b<a) a=b;}
template < typename T > void UMAX(T &a,T b){if(b>a) a=b;}
int n,h[105],t[105],dp[105][105];
int powM(int val,int pw,LL moD=MOD1){
	if(pw<0) return 0;
    int ret=1;
    while(pw){
        if(pw&1) ret=((LL)ret*(LL)val)%moD;
        val=((LL)val*(LL)val)%moD;
        pw>>=1;
    }
    return ret%moD;
}
int calsum(int r,int l){
	return (powM(2,r)+MOD1-powM(2,l))%MOD1;
}
bool cmp(int A,int B){
	return h[A]<h[B];
}
int main(){
    // inputting start
    // 数据结构记得初始化！ n，m别写反！
    int i,j,k,res=0;
	scanf("%d",&n);
	for(i=0;i<n;++i){
		scanf("%d",h+i);
		t[i]=i;
	}
    #ifdef LOCAL
        TStart();
    #endif
    // calculation start
    // 数据结构记得初始化！ n，m别写反！
	t[n]=n;
	h[n]=1;
	sort(t,t+n+1,cmp);
	for(i=0;i<=n;++i){
		j=t[i];
		k=t[i+1];
		if(i==n) k=-1;
		if(h[j]<=h[0]){
			dp[0][j]=(2*calsum(h[0]-h[j],(k==-1?-1:(h[0]-h[k]))))%MOD1;
		}
	}
	for(i=0;i<n;++i){
		for(j=0;j<=n;++j){
			if(!dp[i][j]) continue;
			if(i==n-1) res=(res+dp[i][j])%MOD1;
			if(h[j]==h[i]) dp[i][j]=(dp[i][j]*2)%MOD1;
			if(h[i+1]<=h[i]){
				if(h[j]>=h[i+1] && h[j]!=h[i]){
					dp[i][j]=(dp[i][j]*2)%MOD1;
				}
				dp[i+1][(h[j]>=h[i+1])?(i+1):j]+=dp[i][j];
				dp[i+1][(h[j]>=h[i+1])?(i+1):j]%=MOD1;
			}
			else if(h[j]==h[i]){
				for(k=0;k<=n;++k){
					int c=t[k],nx=t[k+1];
					if(k==n) nx=-1;
					if(h[c]>=h[j] && h[c]<=h[i+1]){
						int val=((LL)dp[i][j]*(LL)calsum(h[i+1]-h[c],(nx==-1?-1:h[i+1]-h[nx])))%MOD1;
						dp[i+1][c]+=val;
						dp[i+1][c]%=MOD1;
					}
				}
			}
			else{
				dp[i+1][j]+=((LL)dp[i][j]*(LL)powM(2,h[i+1]-h[i]))%MOD1;
				dp[i+1][j]%=MOD1;
			}
		}
	}
	printf("%d\n",res);
    #ifdef LOCAL
        TReport();
    #endif
    return 0;
}