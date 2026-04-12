#include<bits/stdc++.h>
#define RI(x) x = rit()
#define RII(a,b) a = rit(), b = rit()
#define RIII(a,b,c) a = rit(), b = rit(), c = rit()
#define REP(I, N) for(int I=0;I<int(N);I++)
#define REPP(I, N) for(int I=1;I<=int(N);I++)
#define ll long long
#define SZ(x) (int)(x).size()
#define F first
#define S second
#define PB(x) push_back(x)
inline int rit(){
    int f=0,key=1;
    char ch;
    do{
        ch = getchar();
        if(ch=='-') key=-1;;
    }while(ch<'0'||ch>'9');
    do{
        f = f*10+ch-'0';
        ch = getchar();
    }while(ch>='0'&&ch<='9');
    return f*key;
}
using namespace std;
typedef pair<int,int> P;
int boss[100005];
int n;
struct st{
	int x,y,idx;
}dt[100005];
struct road{
	int u,v,d;
}rd[100005];
int find_boss(int x){
	return boss[x]==x ? x : boss[x] = find_boss(boss[x]);
}
int main(void){
	RI(n);
	REP(i,n){
		RII(dt[i].x, dt[i].y);
		dt[i].idx = i;
	}
	int cur=0;
	sort(dt,dt+n,[](st &a, st &b){
		return a.x < b.x;
	});
	for(int i=1;i<n;++i, ++cur){
		rd[cur].u = dt[i-1].idx;
		rd[cur].v = dt[i].idx;
		rd[cur].d = dt[i].x - dt[i-1].x;
	}
	sort(dt,dt+n,[](st &a, st &b){
		return a.y < b.y;
	});
	for(int i=1;i<n;++i, ++cur){
		rd[cur].u = dt[i-1].idx;
		rd[cur].v = dt[i].idx;
		rd[cur].d = dt[i].y - dt[i-1].y;
	}
	sort(rd,rd+cur,[](road &a, road &b){
		return a.d < b.d;
	});
	REP(i,n) boss[i] = i;
	int ans=0;
	REP(i,cur){
		if(find_boss(rd[i].u)!=find_boss(rd[i].v)){
			ans+=rd[i].d;
			boss[ find_boss(rd[i].u) ] = find_boss(rd[i].v);
		}
	}
	printf("%d\n",ans);
}