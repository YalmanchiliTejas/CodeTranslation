#include <bits/stdc++.h>
using namespace std;
int par[100005];
int get(int u){
	return par[u] == u ? u : par[u] = get(par[u]);
}
struct node{
	int l,r,ind;
	node(int a = 0,int b = 0,int c = 0){
		l = a;r = b;ind = c;
	}
	bool operator<(const node&e)const{
		if(l != e.l)return l < e.l;
		return r < e.r;
	}
};
set<node>st,rst;
int main(){
	//freopen("readin.txt","r",stdin);
	int n;
	scanf("%d",&n);
	for(int i = 0;i < n;i++)par[i] = i;
	for(int i = 0;i < n;i++){
		int l,r;
		scanf("%d%d",&l,&r);
		st.insert(node(l,r,i));
		rst.insert(node(r,l,i));
	}
	vector<node>v;
	set<node>::iterator i = st.begin();
	i++;
	for(set<node>::iterator j = st.begin();i != st.end();j++,i++)
		v.push_back(node(max(i->l,j->l) - min(i->l,j->l),i->ind,j->ind));
	//return 0;
	i = rst.begin();
	i++;
	for(set<node>::iterator j = rst.begin();i != rst.end();j++,i++)
		v.push_back(node(max(i->l,j->l) - min(i->l,j->l),i->ind,j->ind));
	sort(v.begin(),v.end());
	long long ans = 0;
	for(int i = 0;i < v.size();i++){
		if(get(v[i].r) == get(v[i].ind))continue;
		par[get(v[i].r)] = get(v[i].ind);
		ans+=v[i].l;
	}
	cout << ans << endl;
}