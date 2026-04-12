//D
#include<bits/stdc++.h>
using namespace std;

int n;

#define MAX 100002

map<int, vector<int> > x;
map<int, vector<int> > y;
vector < pair<int, int> > v;

struct st{
	int dif;
	bool flag;
	int val1;
	int val2;
};
bool cmp(st a, st b){
	return a.dif < b.dif;
}
vector<st> vv;

struct UF{
	vector<int> belong;
	vector<int> size;
	void resize(int n){
		belong.assign(n + 1, -1);
		size.assign(n + 1, 1);
	}
	inline int root(int b){
		if (belong[b] == -1){
			return b;
		}
		belong[b] = root(belong[b]);
		return belong[b];
	}
	void merge(int a, int b){
		a = root(a);
		b = root(b);
		if (a == b)return;
		belong[a] = b;
		size[b] += size[a];
	}
};

UF uf;

int main(){
	cin >> n;
	for (int i = 0; i < n; i++){
		int a, b;
		scanf("%d%d", &a, &b);
		v.push_back(make_pair(a, b));
		x[a].push_back(i);
		y[b].push_back(i);
	}
	uf.resize(100002);
	for (auto it = x.begin(); it != x.end(); it++){
		for (int j = 1; j < (*it).second.size(); j++){
			uf.merge((*it).second[0], (*it).second[j]);
		}
	}
	for (auto it = y.begin(); it != y.end(); it++){
		for (int j = 1; j < (*it).second.size(); j++){
			uf.merge((*it).second[0], (*it).second[j]);
		}
	}
	for (auto it = x.begin(); it != x.end(); it++){
		auto nex = it;
		nex++;
		if (nex != x.end()){
			vv.push_back({ (*nex).first - (*it).first, false, (*it).first, (*nex).first });
		}
	}
	for (auto it = y.begin(); it != y.end(); it++){
		auto nex = it;
		nex++;
		if (nex != y.end()){
			vv.push_back({ (*nex).first - (*it).first, true, (*it).first, (*nex).first });
		}
	}
	sort(vv.begin(), vv.end(), cmp);
	long long int ans = 0;
	for (int i = 0; i < vv.size(); i++){
		if (vv[i].flag == false){
			vector<int> &A = x[vv[i].val1];
			vector<int> &B = x[vv[i].val2];
			A.resize(1);
			for (int j = 0; j < B.size(); j++){
				if (uf.root(A[0]) != uf.root(B[j])){
					ans += vv[i].dif;
					uf.merge(A[0], B[j]);
				}
			}
		}
		else{
			vector<int> &A = y[vv[i].val1];
			vector<int> &B = y[vv[i].val2];
			A.resize(1);
			for (int j = 0; j < B.size(); j++){
				if (uf.root(A[0]) != uf.root(B[j])){
					ans += vv[i].dif;
					uf.merge(A[0], B[j]);
				}
			}
		}
	}
	printf("%lld\n", ans);
	return 0;
}