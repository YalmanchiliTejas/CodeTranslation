#include<bits/stdc++.h>
using namespace std;

/*#### modular_arithmetic */
class modular_arithmetic{
public:
	int mod;

	modular_arithmetic(){
		mod = 1000000007;
	}
	//No specific settings.
	void set_mod(int _mod){mod = _mod;}
	int add(int x,int y){return (x+y)%mod;}
	int sub(int x,int y){return (x-y+mod)%mod;}
	int mul(int x,int y){return (int)((long long int)x*y%mod);}
	int sqr(int x){return mul(x,x);}

};
/*####*/
modular_arithmetic ma;

#define ran 101111
int s,t,n;
long long int ds[ran], dt[ran];
int cs[ran],ct[ran];
vector<pair<int,int> > e[ran];

void dij(int x,long long int*d,int*c){
	priority_queue<pair<long long int,int> > q;
	for(int i=1; i<=n; i++)d[i] = -1;
	d[x] = 0;
	c[x] = 1;
	q.push(make_pair(0LL, x));
	while(!q.empty()){
		x = q.top().second;
		long long int dis = -q.top().first;
		q.pop();
		if(dis != d[x])continue;
		for(auto p : e[x]){
			int y = p.first, z = p.second;
			if(d[y] == -1 || d[y] > d[x] + z){
				d[y] = d[x] + z;
				c[y] = c[x];
				q.push(make_pair(-d[y], y));
			}else
			if(d[y] == d[x] + z){
				c[y] = ma.add(c[y], c[x]);
			}
		}
	}
}

int main(){
	int m;
	scanf("%d%d%d%d",&n,&m,&s,&t);
	while(m--){
		int x,y,z;
		scanf("%d%d%d",&x,&y,&z);
		e[x].push_back(make_pair(y,z));
		e[y].push_back(make_pair(x,z));
	}
	dij(s,ds,cs);
	dij(t,dt,ct);
	int res = ma.sqr(cs[t]);
	for(int i=1; i<=n; i++){
		if(ds[t] == ds[i] + dt[i] && ds[i] == dt[i]){
			res = ma.sub(res, ma.sqr(ma.mul(cs[i], ct[i])));
		}
		for(auto p : e[i]){
			int x = i, y = p.first, z = p.second;
			if(ds[t] == ds[x] + z + dt[y] && max(ds[x], dt[y]) < min(ds[x] + z, dt[y] + z)){
				res = ma.sub(res, ma.sqr(ma.mul(cs[x], ct[y])));
			}
		}
	}
	printf("%d\n",res);
	return 0;
}
