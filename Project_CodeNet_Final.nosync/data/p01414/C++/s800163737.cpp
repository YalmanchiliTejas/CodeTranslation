#include <bits/stdc++.h>

#define _overload(_1,_2,_3,name,...) name
#define _rep(i,n) _range(i,0,n)
#define _range(i,a,b) for(int i=int(a);i<int(b);++i)
#define rep(...) _overload(__VA_ARGS__,_range,_rep,)(__VA_ARGS__)

#define _rrep(i,n) _rrange(i,n,0)
#define _rrange(i,a,b) for(int i=int(a)-1;i>=int(b);--i)
#define rrep(...) _overload(__VA_ARGS__,_rrange,_rrep,)(__VA_ARGS__)

#define _all(arg) begin(arg),end(arg)
#define uniq(arg) sort(_all(arg)),(arg).erase(unique(_all(arg)),end(arg))
#define getidx(ary,key) lower_bound(_all(ary),key)-begin(ary)
#define clr(a,b) memset((a),(b),sizeof(a))
#define bit(n) (1LL<<(n))
#define popcount(n) (__builtin_popcountll(n))

template<class T>bool chmax(T &a, const T &b) { return (a<b)?(a=b,1):0;}
template<class T>bool chmin(T &a, const T &b) { return (b<a)?(a=b,1):0;}

using namespace std;

const int dx[8]={1,0,-1,0,1,-1,-1,1};
const int dy[8]={0,1,0,-1,1,1,-1,-1};

const int all=(1<<16)-1;
int n,h[20],w[20];
int memo[1<<16];
char board[4][4];
char cur[10][10];

int rec(int mask){
	if(mask==all) return 0;
	int &ret=memo[mask];
	if(ret!=-1) return ret;

	ret=1010;
	
	rep(idx,n){
		rep(si,10)rep(sj,10){
			const int ti=si+h[idx],tj=sj+w[idx];
			if(ti<=3||7<=si) continue;
			if(tj<=3||7<=sj) continue;

			bool ok=true;
			char tar=-1;
            int nmask=mask;
            rep(a,h[idx])rep(b,w[idx]){
                const int ca=si+a,cb=sj+b;
                if(ca<3||7<=ca) continue;
                if(cb<3||7<=cb) continue;
                if(cur[ca][cb]=='*') continue;
 				if(tar==-1||tar==cur[ca][cb])
 					tar=cur[ca][cb];
 				else
 					ok=false; 
                nmask|=bit(4*(ca-3)+(cb-3));
            }

            if(ok&&nmask>mask){
            	if(memo[nmask]!=-1){
            		chmin(ret,rec(nmask)+1);
            	}else{
        			const int change=nmask^mask;
	            	rep(i,4)rep(j,4) if(change&bit(4*i+j)) cur[i+3][j+3]='*';
	            	chmin(ret,rec(nmask)+1);
	            	rep(i,4)rep(j,4) if(change&bit(4*i+j)) cur[i+3][j+3]=board[i][j];
            	}
            }
		}
		if(ret==1) break;
	}
	return ret;
}

int main(void){
	cin >> n;
	rep(i,n) cin >> h[i] >> w[i];

	rep(i,4) rep(j,4) cin >> board[i][j];
	rep(i,10)rep(j,10) cur[i][j]='*';
	rep(i,4)rep(j,4) cur[i+3][j+3]=board[i][j];
	clr(memo,-1);
	cout << rec(0) << endl;
	return 0;
}