#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
#define mp make_pair
#define PI pair<int,int>
#define poly vector<ll>
#define For(i,l,r) for(int i=(int)(l);i<=(int)(r);i++)
#define Rep(i,r,l) for(int i=(int)(r);i>=(int)(l);i--)
#define pb push_back
#define fi first
#define se second
inline char gc(){
    static char buf[100000],*p1=buf,*p2=buf;
    return p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++;
}
#define getchar gc
inline ll read(){
	ll x = 0; char ch = gc(); bool positive = 1;
	for (; !isdigit(ch); ch = gc())	if (ch == '-')	positive = 0;
	for (; isdigit(ch); ch = gc())	x = x * 10 + ch - '0';
	return positive ? x : -x;
}
inline void write(ll a){
    if(a<0){
    	a=-a; putchar('-');
	}
    if(a>=10)write(a/10);
    putchar('0'+a%10);
}
inline void writeln(ll a){write(a); puts("");}
inline void wri(ll a){write(a); putchar(' ');}
inline ull rnd(){
	return ((ull)rand()<<30^rand())<<4|rand()%4;
}
const int B=32000,N=10000005,mod=1e9+7;
int qq,q[N];
ll F[B+1],G[B+1];
PI f[N];
PI operator +(PI a,PI b){
	return mp((ll)a.fi*b.fi%mod,((ll)a.fi*b.se*2+(ll)a.se*b.fi*2+(ll)a.se*b.se+(ll)a.fi*b.fi*2)%mod);
}
ll pw(int h){
	return F[h%B]*G[h/B]%mod;
}
void del(PI &x,int h){
	x.fi=x.fi*pw(h)%mod;
}
int main(){
	For(i,F[0]=1,B)F[i]=F[i-1]*2%mod;
	For(i,G[0]=1,B)G[i]=G[i-1]*F[B]%mod;
	int n=read();
	For(i,1,n){
		int h=read();
		PI zs=mp(1,0);
		if(qq&&q[qq]>=h){
			while(q[qq-1]>=h){
				del(f[qq],q[qq]-q[qq-1]); 
				f[qq-1]=f[qq-1]+f[qq]; qq--;
			}
			del(f[qq],q[qq]-h);
			q[qq]=h; f[qq]=f[qq]+zs;
		}else{
			q[++qq]=h;
			f[qq]=zs;
			
		}
	}
	q[0]=1;
	//For(i,1,qq)cout<<f[i].fi<<" "<<f[i].se<<endl;
	while(qq){
		del(f[qq],q[qq]-q[qq-1]); qq--;
		if(qq)f[qq]=f[qq]+f[qq+1];
	}
	cout<<((ll)f[1].fi*2+f[1].se)%mod<<endl;
}
/*
3
1 2 2

*/