#include <bits/stdc++.h>
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)  for(int i=0;i<(n);++i)
#define FORq(i, m, n) for(int i = (m);i <= (n);++i)
#define SCD(n) scanf("%d",&n)
#define SCD2(m,n) scanf("%d%d",&m,&n)
#define SCD3(m,n,k) scanf("%d%d%d",&m,&n,&k)
#define SCLLD(n) scanf("%lld",&n)
#define SCLLD2(m,n) scanf("%lld%lld",&m,&n)
#define SCLLD3(m,n,k) scanf("%lld%lld%lld",&m,&n,&k)
#define PB push_back
#define MP make_pair
#define ARSCD(A,N) REP(i,N){SCD(A[i]);}
#define ARSCD1(A,N) FORq(i,1,N){SCD(A[i]);}
#define PRINTD(n) printf("%d\n",n)
#define PRINTLLD(n) printf("%lld\n",n)
#define DEBUG printf("%s\n","debug")
#define fst first
#define snd second
#define SIN(x,S) (S.count(x) != 0)
using namespace std;
typedef pair<int,int> PII;
typedef vector<int> VI;
typedef vector < VI > VVI;
typedef long long ll;
typedef long long integer;
//////////////////////////////////////////////////
const int UNIMAX = 100005;
int uni[UNIMAX] = {}; //parent -- size of member , kid -- leader name,def -1

int uniroot(int a){ //return a's leader
	if (uni[a] < 0) return a;
	return uni[a] = uniroot(uni[a]); //uni[a] => 0 , reconnect root directly
}

bool uniconnect(int a,int b){
	a = uniroot(a);
	b = uniroot(b);
	
	if(a==b) return false;
	
	if(uni[a] > uni[b]){
		a ^= b;
		b ^= a;
		a ^= b;
	}
	
	uni[a] = uni[a] + uni[b]; // membersize++
	uni[b] = a;
	return true;
}

bool uniisConnect(int a,int b){
	return (uniroot(a) == uniroot(b));
}

int unireset() {
	REP(i,UNIMAX){
		uni[i] = -1;
	}
}

int unisize (int a){
	return (-uni[uniroot(a)]);
}

int main(){
    int N;
    SCD(N);
    vector< PII > xy;
    map< PII , int> f;
    REP(i,N){
        int x,y; SCD2(x,y);
        PII p = MP(x,y);
        f[p] = i;
        xy.PB(p);
    }

    priority_queue< pair<int,PII> , vector<pair<int,PII> > ,greater<pair<int,PII> > >Q;
    sort(xy.begin(),xy.end());
    REP(i,N-1){ // x
        int x1,y1,x2,y2;
        x1 = xy[i].fst;
        x2 = xy[i+1].fst;
        y1 = xy[i].snd;
        y2 = xy[i+1].snd;

        int cost = min(abs(x2-x1) , abs(y2-y1));
        PII p1 = MP(x1,y1);
        PII p2 = MP(x2,y2);

        Q.push(MP(cost,MP(f[p1],f[p2])));
    }

    sort(xy.begin(),xy.end(),
    [](const PII& x, const PII& y){return x.second < y.second;}
    );

     REP(i,N-1){ // y
        int x1,y1,x2,y2;
        x1 = xy[i].fst;
        x2 = xy[i+1].fst;
        y1 = xy[i].snd;
        y2 = xy[i+1].snd;

        int cost = min(abs(x2-x1) , abs(y2-y1));
        PII p1 = MP(x1,y1);
        PII p2 = MP(x2,y2);

        Q.push(MP(cost,MP(f[p1],f[p2])));
    }

    unireset();
    int connected = 0;
    integer ans = 0;

    while((!Q.empty()) and (connected < N-1)){
        PII p = Q.top().snd;
        integer cost = Q.top().fst;
        Q.pop();

        if (uniisConnect(p.fst,p.snd)) continue;
        uniconnect(p.fst,p.snd);
        ans = cost + ans;
        connected++;
        //printf("%d --> %d, cost = %d\n",p.fst,p.snd,cost);
    }

    PRINTLLD(ans);
}