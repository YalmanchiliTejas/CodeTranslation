#include<cstdio>
#include<cstring>
#include<algorithm>

#define Fast register
#define uint unsigned int
#define LL long long

struct IO{
	#define ISIZE 262144
	#define OSIZE 262144

	char IBUF[ISIZE],*IS,*IT;
	char OBUF[OSIZE+128],*OS,*OT;

	IO():IS(IBUF),IT(IBUF),OS(OBUF),OT(OBUF+OSIZE){}
	~IO(){Flush();}
	
	inline char Getchar(){return(IS==IT)&&(IT=(IS=IBUF)+fread(IBUF,1,ISIZE,stdin),IS==IT)?EOF:*IS++;}
	template<class T>inline IO&operator>>(T&x){
		Fast T s=0;Fast char c;
		if(IS+25<IT){
			do c=*IS++;while(c<48||c>57);
			do s=s*10+c-48,c=*IS++;while(c>47&&c<58);
		}else{
			do c=Getchar();while(c<48||c>57);
			do s=s*10+c-48,c=Getchar();while(c>47&&c<58);
		}return(x=s,*this);
	}

	inline void Flush(){fwrite(OBUF,1,OS-OBUF,stdout);OS=OBUF;}
	inline void Putchar(const char&c){if(OS>OT)Flush();*OS++=c;}
	inline IO&operator<<(const char&c){return(Putchar(c),*this);}
	template<class T>inline IO&operator<<(T x){
		if(OS>OT)Flush();
		static char OStack[30];static int Top;Top=0;
		if(x<0)*OS++='-',x=-x;
		do OStack[++Top]=x%10|48;while(x/=10);
		while(Top)*OS++=OStack[Top--];
		return*this;
	}

	#undef ISIZE
	#undef OSIZE
}io;

#define Maxn 200001

int X[Maxn];
int Xx[Maxn];

int main(){
	Fast int n;io>>n;
	for(Fast int i=1;i<=n;++i)io>>X[i];
	memcpy(Xx+1,X+1,n<<2);
	std::sort(Xx+1,Xx+n+1);
	for(Fast int i=1,Mid=n>>1,Ans1=Xx[Mid],Ans2=Xx[Mid+1];i<=n;++i)
		io<<((X[i]<=Ans1)?Ans2:Ans1)<<'\n';
	return 0;
}