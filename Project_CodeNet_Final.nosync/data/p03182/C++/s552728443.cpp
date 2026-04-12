# include "algorithm"
# include "iostream"
# include "cstdio"
# define LC (x<<1)
# define RC (x<<1|1)

using namespace std;

const int maxm=2e5+10;
const long long Inf=1ll<<50;

int N,M;

struct Segment_Tree{
	int Left;
	int Right;
	long long Max;
	long long Lazy;
	# define Left(x) Tree[x].Left
	# define Right(x) Tree[x].Right
	# define Max(x) Tree[x].Max
	# define Lazy(x) Tree[x].Lazy
}Tree[maxm<<2];

struct line{
	int Left;
	int Right;
	int A;
	# define L(x) Line[x].Left
	# define R(x) Line[x].Right
	# define A(x) Line[x].A
}Line[maxm];

inline bool Comp(line x,line y){
	return x.Right==y.Right?x.Left<y.Left:x.Right<y.Right;
}

inline void Spread(int x){
	if(Lazy(x)){
		Max(LC)+=Lazy(x);
		Max(RC)+=Lazy(x);
		Lazy(LC)+=Lazy(x);
		Lazy(RC)+=Lazy(x);
		Lazy(x)=0;
	}
	return;
}

inline void Update(int x){
	Max(x)=max(Max(LC),Max(RC));
	return;
}

void Build(int x,int l,int r){
	Left(x)=l,Right(x)=r;
	if(l==r){
		return;
	}
	int Mid=l+r>>1;
	Build(LC,l,Mid);
	Build(RC,Mid+1,r);
	return;
}

void Change(int x,int l,int r,long long Data){
	if(l<=Left(x) && r>=Right(x)){
		Lazy(x)+=Data;
		Max(x)+=Data;
		return;
	}
	Spread(x);
	int Mid=(Left(x)+Right(x))>>1;
	if(l<=Mid) Change(LC,l,r,Data);
	if(r>Mid) Change(RC,l,r,Data);
	Update(x);
	return;
}

long long Query(int x,int l,int r){
	if(l<=Left(x) && r>=Right(x)){
		return Max(x);
	}
	Spread(x);
	int Mid=(Left(x)+Right(x))>>1;
	long long Result=-Inf;
	if(l<=Mid) Result=max(Result,Query(LC,l,r));
	if(r>Mid) Result=max(Result,Query(RC,l,r));
	return Result;
}

int main(){
	register int i,k=1;
	scanf("%d%d",&N,&M);
	Build(1,0,N);
	for(i=1;i<=M;i++) scanf("%d%d%d",&L(i),&R(i),&A(i));
	sort(Line+1,Line+1+M,Comp);
	for(i=1;i<=N;i++){
		Change(1,i,i,Query(1,0,i));
		while(R(k)==i && k<=M){
			Change(1,L(k),R(k),A(k));
			k++;
		}
	}
	printf("%lld",Query(1,0,N));
	return 0;
}