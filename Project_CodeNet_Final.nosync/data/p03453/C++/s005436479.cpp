#include <bits/stdc++.h>
#define F first
#define S second
#define dq deque
#define vc vector
#define INF (0x3f3f3f3f)
#define LINF ((long long)(0x3f3f3f3f))
#define Pb push_back
#define Mp make_pair
#define ll long long
#define _tp template
#define _tyn typename
#define Pf push_front
#define sint short int
#define ull unsigned ll
#define pii pair<int,int>
#define uint unsigned int
#define B cout << "BreakPoint" << endl;
#define Ms(_data) memset(_data,0,sizeof(_data))
#define Fin(_filename) freopen(_filename,"r",stdin)
#define Fout(_filename) freopen(_filename,"w",stdout)
#define Msn(_data,_num) memset(_data,_num,sizeof(_data))
#define Fastio ios_base::sync_with_stdio(false);cin.tie(0);
#define O(x) cerr << #x << " " << x << endl;
using namespace std;
#define Mymax(a,b) if(a<b) a = b;
#define Mymin(a,b) if(a>b) a = b;
void Print(int _x){printf("%d\n",_x);}
void Print(ll _x){printf("%lld\n",_x);}
_tp<_tyn T>void Print( T _a[] , int _s , int _t ){
	for( int i = _s ; i <= _t ; i++ )
		cout << _a[i] << " ";
   	cout << endl;
}
#define il inline
#define rg register
struct InputReader{
    static const int bs = 100000;
    char buf[bs]; int p;
    il InputReader():p(bs){}
    il void Flush(){
        p = 0;
        fread(buf,1,bs,stdin);
    }
    il char C(){
        if(p >= bs) Flush();
        return buf[p++];
    }
	il int Getnum(){
		char ch = C();
        while( ch < '0'  ||  ch > '9' ) ch = C();
		return (int)(ch-'0');
	}
    il int operator() (){
        int ans = 0;
        char ch = C();
		int fu = 1;
		while( ch < '0'  ||  ch > '9' ){
			if( ch == '-' ) fu = -1;
			ch = C();
		}
        while( ch >= '0'  &&  ch <= '9' ){
            ans *= 10;
            ans += ch-'0';
            ch = C();
        }
        return ans * fu;
    }
	il ll Readll(){
		ll ans = 0LL;
		char ch = Getnum()+'0';
        while( ch >= '0'  &&  ch <= '9' ){
            ans *= 10LL;
            ans += ch-'0';
            ch = C();
        }
        return ans;
	}
	il void Readstring( string &x ){
		x.clear();
		char ch = C();
		while( !isdigit(ch)  &&  !isalpha(ch) ) ch = C();
		int p = 0;
		while( isdigit(ch)  ||  isalpha(ch) ){
			x += ch;
			ch = C();
			p++;
		}
		x[p] = '\0';
	}
	il char Specialread(){
		char ch = C();
		while( ch != '+'  &&  ch != '?' ) ch = C();
		return ch;
	}
}In;
il void Read( int &x ){ x = In(); }
il void Read( int &x, int &y ){ x = In(); y = In(); }
il void Read( int &x1 , int &x2 , int &x3 ){
	x1 = In(); x2 = In(); x3 = In();
}
il void Read( int &x1 , int &x2 , int &x3 , int &x4 ){
	x1 = In(); x2 = In(); x3 = In(); x4 = In();
}
il void Read( ll &x ){
	x = In.Readll();
}
clock_t _starttime,_endtime;
il void FILEIO(){
	#ifdef WIN32
		_starttime = clock();
		Fin("in.in");
	#endif
}
#ifdef WIN32
	#include <windows.h>
	#include <psapi.h>
	#pragma comment(lib,"Psapi.lib")
#endif
il void END(){
	#ifdef WIN32
		_endtime = clock();
		double _timeuse = (_endtime-_starttime)* 1000.0 / CLOCKS_PER_SEC;
		printf("\n\nTime usage:\n%.0lf ms\n",_timeuse);
		HANDLE _handle = GetCurrentProcess();
		PROCESS_MEMORY_COUNTERS pmc;
		GetProcessMemoryInfo(_handle,&pmc,sizeof(pmc));
		double _memuse = pmc.PeakPagefileUsage/1024.00/1024.00;
		printf("Memory usage:\n%.1lf MB\n\n",_memuse);
	#endif
	exit(0);
}
#define For(i,j) for( int (i) = 1 ; (i) <= (j) ; (i)++ )
#define For0(i,j) for( int (i) = 0 ; (i) < (j) ; (i)++ )
#define fOR(i,j) for( int (i) = (j) ; (i) >= 1 ; (i)-- )
/////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////
#define MOD 1000000007LL
#define MAXN 100010
struct Edge{
	int to;ll cost;
	Edge(){}
	Edge( int tt , ll cc ){
		to = tt;
		cost = cc;
	}
};

int n,m,S,T;
vc<Edge> e[MAXN],g[MAXN];
ll diss[MAXN],dist[MAXN];
ll mindis;

bool inque[MAXN];
queue<int> q;
void Spfa( int stpos , ll dis[] ){
	Ms(inque);
	For(i,n) dis[i] = 1000000000000000000LL;
	while(!q.empty()) q.pop();

	inque[stpos] = 1; dis[stpos] = 0;
	q.push(stpos);
	while( !q.empty() ){
		int u = q.front();
		inque[u] = 0;
		q.pop();
		For0(i,e[u].size()){
			Edge now = e[u][i];
			int v = now.to;
			if( dis[v] > dis[u] + now.cost ){
				dis[v] = dis[u] + now.cost;
				if( !inque[v] ){
					inque[v] = 1;
					q.push(v);
				}
			}
		}
	}
}

ll mem[MAXN][2];
// 0:S
// 1:T
ll Dfs( int pos , int goal , int ceng ){
	if( pos == goal ) return mem[pos][ceng] = 1LL;
	if( mem[pos][ceng] != -1 ) return mem[pos][ceng];
	ll ret = 0;
	For0(i,g[pos].size()){
		Edge now = g[pos][i];
		int v = now.to;
		if( !ceng  &&  diss[pos] + now.cost + dist[v] != mindis ) continue;
		if( ceng  &&  dist[pos] + now.cost + diss[v] != mindis ) continue;
		ret += Dfs(v,goal,ceng);
		ret %= MOD;
	}
	return mem[pos][ceng] = ret;
}

int main(){
	FILEIO();

	Read(n,m);
	Read(S,T);
	For(i,m){
		int a,b; ll c;
		Read(a,b);
		Read(c);
		c %= MOD;
		e[a].Pb( Edge(b,c) );
		e[b].Pb( Edge(a,c) );
	}

	Spfa(S,diss);
	Spfa(T,dist);
	mindis = diss[T];
	//Print(diss,1,n);
	//Print(dist,1,n);

	For(i,n)
		For0(j,e[i].size()){
			if( diss[i] + e[i][j].cost + dist[e[i][j].to] == mindis )
				g[i].Pb(e[i][j]);
			else if( dist[i] + e[i][j].cost + diss[e[i][j].to] == mindis )
				g[i].Pb(e[i][j]);
		}

	/*
	For(i,n)
		For0(j,g[i].size())
			printf("%d %d %d\n",i,g[i][j].to,g[i][j].cost);
	*/

	Msn(mem,-1);
	ll tot = Dfs(S,T,0);
	tot *= tot;
	tot %= MOD;
	//O(tot);
	Dfs(T,S,1);

	ll ban = 0LL;
	For(i,n){
		if( !g[i].size() ) continue;
		if( diss[i] == dist[i] ){
			//O(i);
			ban += ((mem[i][1]*mem[i][0]%MOD)*(mem[i][1]*mem[i][0]%MOD))%MOD;
			ban %= MOD;
			continue;
		}
		if( diss[i]*2LL < mindis ){
			//O(i);
			For0(j,g[i].size()){
				int v = g[i][j].to;
				if( diss[v]*2LL > mindis ){
					//B
					ban += ((mem[i][1]*mem[v][0]%MOD)*(mem[i][1]*mem[v][0]%MOD))%MOD;
					ban %= MOD;
				}
			}
		}
	}

	ll ans = tot - ban;
	ans = ((ans%MOD)+MOD) % MOD;
	printf("%lld\n",ans);

	END();
}
