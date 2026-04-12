#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;

ll inf = 1e9+7;
class UnionFind{
private:
    vector<int> p,s;
	int cnt;
public:
	UnionFind(){}
	UnionFind(int N){
		cnt = N;
		p = s = vector<int>(N+1,0);
		for(int i=1;i<=N;i++){
			p[i] = i; s[i] = 1;
		}
	}
	int find(int x){
		if(p[x]==x) return x;
		else return p[x] = find(p[x]);
	}
	void unite(int x,int y){
		x = find(x); y = find(y);
		if(x==y) return;
		if(s[x]>s[y]){
			p[y] = x;
			s[x] += s[y];
		}else{
			p[x] = y;
			s[y] += s[x];
		}
		cnt--;
	}
	bool is_same_set(int x,int y) {return find(x)==find(y);}
	int size(int x) {return s[find(x)];}
	int compnents_number(){return cnt;}
};

int N,M;
int main(){
	while(cin >> N >> M && N>0){
		vector<ll> p2(N+1,1);
		vector<int> checked(N+1,0);
		for(int i=1;i<=N;i++) p2[i] = 2*p2[i-1]%inf;
		int a,b;
		UnionFind uf(N);
		for(int i=0;i<M;i++){
			cin >> a >> b;
			uf.unite(a,b);
		}
		ll ans = 1,num = 0;
		for(int i=1;i<=N;i++){
			if(!checked[uf.find(i)]){
				checked[uf.find(i)] = 1;
				if(uf.size(i)>=2) num++;
			}
		}
		int s = uf.compnents_number();
		if(s==1) cout << (N==1? 2:3) << endl;
		else if(s==N) cout << p2[N] << endl;
		else cout << (p2[s]+1)%inf << endl;
	}
}
