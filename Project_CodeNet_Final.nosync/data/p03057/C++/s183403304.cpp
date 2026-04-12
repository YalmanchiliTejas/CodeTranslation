#include <cstdio>
#include <algorithm>

using std::min;

const int MOD=1000000007;

const int MAXN=200011, MAXM=200011;

inline int sum(const int &a, const int &b){
	return (a+b>=MOD)?(a+b-MOD):(a+b);
}

inline int mul(const int &a, const int &b){
	return (int)((1LL*a*b)%(long long)(MOD));
}

inline void add(int &f, const int &v){
	f+=v;if(f>=MOD)	f-=MOD;
}

int N, M;
int A[MAXM];
char input[MAXM];
int F[MAXN];

inline bool AllZero(){
	int Cnt=0;
	for(int i=1;i<=M;++i)	Cnt+=!A[i];
	return Cnt==M;
}

int main(){
	
	scanf("%d%d", &N, &M);
	scanf("%s", input);
	for(int i=1;i<=M;++i)	A[i]=input[i-1]!=input[0];
	
	if(AllZero()){
		int F[2][2], T[2][2];
		F[0][0]=F[1][1]=1;
		F[0][1]=F[1][0]=0;
		for(int i=2;i<=N;++i){
			for(int s=0;s<2;++s)
				for(int n=0;n<2;++n)
					T[s][n]=0;
			for(int s=0;s<2;++s)
				for(int n=0;n<2;++n)
					for(int c=0;c<2;++c)
						if(n+c<2)	add(T[s][c], F[s][n]);
			for(int s=0;s<2;++s)
				for(int n=0;n<2;++n)
					F[s][n]=T[s][n];
		}
		int Ans=0;
		for(int s=0;s<2;++s)
			for(int n=0;n<2;++n)
				if(s+n<2)	add(Ans, F[s][n]);
		printf("%d\n", Ans);
	}
	else{
		int Lim=N;
		for(int i=1, c=0, p=0;i<=M;++i){
			if(A[i]){
				if(c&1)	Lim=min(Lim, c+1);
				else if(!p)	Lim=min(Lim, c+2);
				c=0;p=i;
			}
			else	++c;
		}
		F[0]=F[2]=1;
		for(int i=4;i<=N;i+=2){
			F[i]=sum(F[i-2], F[i-2]);
			if(i>=Lim+2){
				add(F[i], MOD-F[i-(Lim+2)]);
			}
		}
		int Ans=0;
		for(int i=2;i<=Lim;i+=2){
			add(Ans, mul(F[N-i], i));
		}
		printf("%d\n", Ans);
	}
	
	return 0;
}