#import<stdio.h>
#define f(A,B) (t=d[5-B],d[5-B]=d[5-A],d[5-A]=d[B],d[B]=d[A],d[A]=t)
main(){int d[6],t,n,r,i;char s[9];while(scanf("%d",&n),n){for(r=i=1;i<7;++i)d[i-1]=i;while(n--){scanf("%s",s);if(*s=='N')f(0,4);if(*s=='S')f(0,1);if(*s=='E')f(0,2);if(*s=='W')f(0,3);if(*s=='R')f(1,3);if(*s=='L')f(1,2);r+=*d;}printf("%d\n",r);}return 0;}