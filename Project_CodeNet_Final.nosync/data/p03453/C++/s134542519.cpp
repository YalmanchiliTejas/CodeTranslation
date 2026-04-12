#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define mp make_pair
#define gc getchar
#define pb push_back
#define eb emplace_back
#define all(x) (x).begin(),(x).end()
#define x1 uvuvwevwevwe
#define y1 onyetenyevwe
#define x2 ugwemubwem
#define y2 ossas
#define distance distdist
#define cout if(false)cout
typedef long long LL;
typedef long double LD;
typedef pair<int,int> pii;
template <typename T> void scan(T &angka){
	angka=0;char input=gc();T kali=1;
	while(!(48<=input&&input<=57)){	if(input=='-')	kali=-1;input=gc();}
	while(48<=input&&input<=57)	angka=(angka<<3)+(angka<<1)+input-48,input=gc();angka*=kali;
}
template <typename T1,typename T2> void scan(T1 &angka1,T2 &angka2){
	scan(angka1);scan(angka2);
}
const LL mods=1000000007;
struct M{
	LL x;
	M(){
		x=0;
	}
	M(LL angka){
		if(angka>=mods||angka<=-mods)
			angka%=mods;
		if(angka<0)
			angka+=mods;
		x=angka;
	}
	
	M operator + (const M &other) const{
		return M(x+other.x);
	}
	M operator - (const M &other) const{
		return M(x-other.x);
	}
	M operator * (const M &other) const{
		return M(x*other.x);
	}
	M operator - () const{
		return M(-x);
	}
	bool operator == (const M &other) const{
		return x==other.x;
	}
};
const LL INF=1000000000000000LL;
const int MAXN=100000;
int nodes,edge,s,t;
vector <pii> node[MAXN+5];
vector <pair<pii,int> >edgelist;
LL jarak[2][MAXN+5],distance;
M cara[2][MAXN+5],ans;
priority_queue <pair<LL,int> > cari;
void dijkstra(int id,int awal){
	for(int i=1;i<=nodes;i++)
		jarak[id][i]=INF;
	
	jarak[id][awal]=0;
	cara[id][awal]=1;
	cari.push(mp(-jarak[id][awal],awal));
	while(!cari.empty())
	{
		pair<LL,int> tops=cari.top();
		cari.pop();
		tops.fi=-tops.fi;
		if(tops.fi>jarak[id][tops.se])
			continue;
		assert(tops.fi==jarak[id][tops.se]);
		for(auto v:node[tops.se])
		{
			LL temp=(LL) v.se+tops.fi;
			if(temp<jarak[id][v.fi])
			{
				jarak[id][v.fi]=temp;
				cara[id][v.fi]=cara[id][tops.se];
				cari.push(mp(-jarak[id][v.fi],v.fi));
			}
			else if(temp==jarak[id][v.fi])
			{
				cara[id][v.fi]=cara[id][v.fi]+cara[id][tops.se];
			}
		}
	}
}
int main()
{
	scan(nodes,edge);
	scan(s,t);
	for(int i=0;i<edge;i++)
	{
		int u,v,d;
		scan(u,v);
		scan(d);
		edgelist.eb(mp(u,v),d);
		node[u].eb(v,d);
		node[v].eb(u,d);
	}
	dijkstra(0,s);
	dijkstra(1,t);
	assert(cara[0][t]==cara[1][s]);
	assert(jarak[0][t]==jarak[1][s]);
	ans=cara[0][t]*cara[1][s];
	distance=jarak[0][t];
	cout<<"ans awalnya "<<ans.x<<endl;
	
	for(auto isi:edgelist)
	{
		int jenis;
		LL temp=distance+1;
		temp=min(temp,(LL) jarak[0][isi.fi.fi]+jarak[1][isi.fi.se]+(LL) isi.se);
		jenis=(temp==distance)?0:1;
		temp=min(temp,(LL) jarak[1][isi.fi.fi]+jarak[0][isi.fi.se]+(LL) isi.se);
		assert(temp>=distance);
		if(temp!=distance)
			continue;
		if((jarak[jenis][isi.fi.fi]<((LL) (distance+1LL)/2LL))&&(jarak[jenis^1][isi.fi.se]<((LL) (distance+1LL)/2LL)))
		{
			ans=ans-(cara[jenis][isi.fi.fi]*cara[jenis^1][isi.fi.se])*(cara[jenis][isi.fi.fi]*cara[jenis^1][isi.fi.se]);
		}
	}
	cout<<"by edge "<<ans.x<<endl;
	
	for(int i=1;i<=nodes;i++)
	{
		if(jarak[0][i]+jarak[1][i]!=distance)
			continue;
		if(jarak[0][i]==jarak[1][i])
			ans=ans-(cara[0][i]*cara[1][i])*(cara[0][i]*cara[1][i]);
	}
	printf("%lld\n",ans.x);
}