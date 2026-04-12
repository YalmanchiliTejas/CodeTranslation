#include <cstdio>
#include <algorithm>
#define Pr(f,...) printf(f,##__VA_ARGS__),fflush(stdout)
#define rep(i,s,t) for(int i=s;i<=(t);++i)
#define dec(i,s,t) for(int i=s;i>=(t);--i)
#define lop(i,s,t) for(int i=s;i<(t);++i)
using namespace std; 

const int N=200050,P=1e9+7; 

int n,m,limit,f[N],sum[N]; 
char s[N]; 

int main(int argc,char *argv[]){
//	freopen("d.in.cpp","r",stdin); 
    scanf("%d%d%s",&n,&m,s); 
    if(s[0]=='B')lop(i,0,m)s[i]=s[i]=='R'?'B':'R';
	//Pr("%d,%d,%s\n",n,m,s);  
    while(m&&s[m-1]=='R')--m;
    if(m==0){
    	f[0]=2,f[1]=1;
		rep(i,2,n)f[i]=(f[i-1]+f[i-2])%P;
		printf("%d\n",f[n]); 
		return 0; 	
    }
    if(n%2!=0){
        puts("0"); 
        return 0; 
    }
    limit=n-1; 
    for(int p=0,prv=0;p<m;++p){
        while(p<m&&s[p]=='R')++p;
		if(prv==0){
            if(p-prv%2==1)limit=p-prv;
            else limit=p-prv+1;
        }
        if((p-prv)%2==1)limit=min(limit,p-prv);
        //printf("%d\n",p-prv); 
        prv=p+1;
    }          
    //Pr("limit=%d\n",limit); 
	f[1]=sum[1]=0,f[2]=sum[2]=2;
	for(int i=4;i<=n;i+=2){
		sum[i-1]=(sum[i-2]+f[i-1])%P;
		if(i<=limit+1)(f[i]+=i)%=P;
		(f[i]+=(sum[i-1]-sum[max(1,i-limit-2)]+P)%P)%=P;
		sum[i]=(sum[i-1]+f[i])%P;
	}
	printf("%d\n",f[n]); 
    return 0; 
}    