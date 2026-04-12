#include<cstdio>

inline char nc(){
    static char buf[100000],*p1=buf,*p2=buf;
    return p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++;
}

inline double read(){
    char ch=nc();
    double sum=0;
    while(!(ch>='0'&&ch<='9')) ch=nc();
    while(ch>='0'&&ch<='9') sum=sum*10+ch-48,ch=nc();
    return sum;
}

int main(){
	double r1=read(),r2=read();
	printf("%.10lf",r1*r2/(double)(r1+r2));
	return 0;
}