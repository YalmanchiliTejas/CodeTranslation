# include "iostream"
# include "cstdio"
# include "cstring"

using namespace std;

const int maxm=1e5+10;
const int maxn=1e2+10;
const int Mod=1e9+7;

char S[maxm];
int K,Len;
long long DP[maxm][maxn];

int main(){
	register int i,j,l,Num=0;
	register long long Ans=0;
	scanf("%s%d",S,&K);
	Len=strlen(S);
	DP[0][0]=1;
	for(i=1;i<Len;i++){
		for(l=0;l<=9;l++){
			for(j=0;j<=K;j++){
				DP[i][(j+l)%K]=(DP[i][(j+l)%K]+DP[i-1][j])%Mod;
			}
		}
	}
	for(i=0;i<Len;Num=(Num+S[i]-'0')%K,i++){
		for(j=0;j<S[i]-'0';j++){
			Ans=(Ans+DP[Len-i-1][(K-(Num+j)%K)%K])%Mod;
		}
	}
	if(Num) Ans--;
	Ans=(Ans+Mod)%Mod;
	printf("%lld",Ans);
	return 0;
}