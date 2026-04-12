#define __USE_MINGW_ANSI_STDIO 0
#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9;
const int MOD = 1000000007;


int main(){
	int N;
	cin >> N;
	vector<string> S(N);
	for(int i=0;i<N;i++)cin >> S[i];
	int a=INF,b=INF,c=INF,d=INF,e=INF,f=INF,g=INF,h=INF,i=INF,j=INF,k=INF,l=INF,m=INF,n=INF,o=INF,p=INF,q=INF,r=INF,s=INF,t=INF,u=INF,v=INF,w=INF,x=INF,y=INF,z=INF;
	for(int I=0;I<N;I++){
		int tmpa=0,tmpb=0,tmpc=0,tmpd=0,tmpe=0,tmpf=0,tmpg=0,tmph=0,tmpi=0,tmpj=0,tmpk=0,tmpl=0,tmpm=0,tmpn=0,tmpo=0,tmpp=0,tmpq=0,tmpr=0,tmps=0,tmpt=0,tmpu=0,tmpv=0,tmpw=0,tmpx=0,tmpy=0,tmpz=0;
		for(int J=0;J<S[I].length();J++){
			if(S[I][J]=='a')tmpa++;
			 if(S[I][J]=='b')tmpb++;
			 if(S[I][J]=='c')tmpc++;
			 if(S[I][J]=='d')tmpd++;
			 if(S[I][J]=='e')tmpe++;
			 if(S[I][J]=='f')tmpf++;
			 if(S[I][J]=='g')tmpg++;
			 if(S[I][J]=='h')tmph++;
			 if(S[I][J]=='i')tmpi++;
			 if(S[I][J]=='j')tmpj++;
			 if(S[I][J]=='k')tmpk++;
			 if(S[I][J]=='l')tmpl++;
			 if(S[I][J]=='m')tmpm++;
			 if(S[I][J]=='n')tmpn++;
			 if(S[I][J]=='o')tmpo++;
			 if(S[I][J]=='p')tmpp++;
			 if(S[I][J]=='q')tmpq++;
			 if(S[I][J]=='r')tmpr++;
			 if(S[I][J]=='s')tmps++;
			 if(S[I][J]=='t')tmpt++;
			 if(S[I][J]=='u')tmpu++;
			 if(S[I][J]=='v')tmpv++;
			 if(S[I][J]=='w')tmpw++;
			 if(S[I][J]=='x')tmpx++;
			 if(S[I][J]=='y')tmpy++;
			 if(S[I][J]=='z')tmpz++;
			

	}
	a=min(a,tmpa);b=min(b,tmpb);c=min(c,tmpc);d=min(d,tmpd);e=min(e,tmpe);f=min(f,tmpf);g=min(g,tmpg);h=min(h,tmph);i=min(i,tmpi);j=min(j,tmpj);k=min(k,tmpk);l=min(l,tmpl);m=min(m,tmpm);n=min(n,tmpn);o=min(o,tmpo);p=min(p,tmpp);q=min(q,tmpq);r=min(r,tmpr);s=min(s,tmps);t=min(t,tmpt);u=min(u,tmpu);v=min(v,tmpv);w=min(w,tmpw);x=min(x,tmpx);y=min(y,tmpy);z=min(z,tmpz);
	
	}
	
	string ans=string(a,'a')+ string(b,'b')+ string(c,'c')+ string(d,'d')+ string(e,'e')+ string(f,'f')+ string(g,'g')+ string(h,'h')+ string(i,'i')+ string(j,'j')+ string(k,'k')+ string(l,'l')+ string(m,'m')+ string(n,'n')+ string(o,'o')+ string(p,'p')+ string(q,'q')+ string(r,'r')+ string(s,'s')+ string(t,'t')+ string(u,'u')+ string(v,'v')+ string(w,'w')+ string(x,'x')+ string(y,'y')+ string(z,'z');
	cout <<ans<<endl;
	}
