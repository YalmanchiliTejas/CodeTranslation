#include <cstdio>
#include <cctype>
#include <string>

using std::string;

inline void setIO(string file){
	string in=file+".in",out=file+".out";
	freopen(in.c_str(),"r",stdin);
	freopen(out.c_str(),"w",stdout);
}

template<typename type>
inline void read(type &x){
	int pm=1; char c;
	do{
		c=getchar();
		if(c=='-') pm=-1;
	}while(!isdigit(c));
	x=c^'0';
	while(c=getchar(),isdigit(c))
		x=x*10+(c^'0');
	x*=pm;
}

template<typename type>
void write(type x,char c=0){
	if(x<0) putchar('-'),x=-x;
	if(x>9) write(x/10);
	putchar(x%10|'0');
	if(c) putchar(c);
}

#include <algorithm>

using std::min;

int n,m;

inline long long cal1(){
	long long ret=0;
	for(int l=m+1,r;l<=n;l=r+1){
		r=min(n,(n+1)/((n+1)/l));
		ret+=(long long)(n+1)/l*(((long long)(l+r)*(r-l+1)>>1)-(long long)(r-l+1)*m);
	}
	return ret;
}

inline int bin_chop_l(int l,int r){
	int mid,div=n/l;
	while(l<=r){
		mid=l+r>>1;
		if(mid*(div+1)>n+1)
			r=mid-1;
		else l=mid+1;
	}
	return l;
}

inline int bin_chop_r(int l,int r){
	int mid,div=n/l;
	while(l<=r){
		mid=l+r>>1;
		if(mid*div<=n-m)
			l=mid+1;
		else r=mid-1;
	}
	return r;
}

inline long long cal2(){
	long long ret=0;
	for(int l=m+1,r,lp,rp;l<=n;l=r+1){
		r=n/(n/l);
		lp=bin_chop_l(l,r);
		rp=bin_chop_r(l,r);
		ret+=(long long)(rp-lp+1)*(n-m+1)-(long long)n/l*((long long)(lp+rp)*(rp-lp+1)>>1);
	}
	return ret;
}

int main(){
	//setIO("mod");
		read(n),read(m);
		if(m==0) write((long long)n*n,'\n');
		else write(cal1()+cal2(),'\n');
	return 0;
}