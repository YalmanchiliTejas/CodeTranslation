#include <bits/stdc++.h>
#define MEM(x,v) memset(x,v,sizeof(x))
#define MEC(x,y) memcpy(x,y,sizeof(x))
using namespace std;
typedef long long ll;
typedef double db;
typedef pair<int,int> pii;
const int M=1e5+5;
template <class T>
inline void Rd(T &p){
	p=0;char c;
	while(c=getchar(),c<48);
	do p=p*10+(c&15);
	while(c=getchar(),c>47);
}
template <class T>
inline void pfn(T p,bool f=true){
	if(p<0)putchar('-'),p=-p;
	else if(p==0)putchar('0');
	static int num[100],tot;
	while(p){num[++tot]=p%10;p/=10;}
	while(tot)putchar(num[tot--]^'0');
	putchar(f?'\n':' ');
}
template <class T>
inline void Max(T &a,T b){if(a<b)a=b;}
template <class T>
inline void Chk(T &a,T b){if(!~b&&(!~a||a>b))a=b;}
deque<int>deq;
int n,w; 
int main(){
	Rd(n);
	int op=1;
	for(int i=1;i<=n;++i){
		Rd(w);
		if(op){deq.push_back(w),op^=1;}
		else deq.push_front(w),op^=1;
	}
	if(op){
		while(!deq.empty()){
			pfn(deq.front(),0);
			deq.pop_front();
		}
		puts("");
	}else{
		while(!deq.empty()){
			pfn(deq.back(),0);
			deq.pop_back();
		}
		puts("");
	}
}
