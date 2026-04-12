#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
#include<vector>
#include<set>
#include<list>
#include<queue>
#include<cmath>
#include<functional>
#include<algorithm>
#include<climits>
#define INF (1<<29)
#define rep(i,n) for(int i=0;i<(n);i++)
using namespace std;



struct StarrySkyTree{
	int n;
	std::vector<long long> segv,segAdd;
	void add(int a,int b,int x,int k,int l,int r){
		if(r<=a || b<=l)return;
		if(a<=l && r<=b){
			segAdd[k] += x;
			return;
		}
		int m=(l+r)/2;
		add(a,b,x,2*k+1,l,m);
		add(a,b,x,2*k+2,m,r);
		segv[k]=std::min(segAdd[2*k+1]+segv[2*k+1] ,segAdd[2*k+2]+segv[2*k+2]);
	}
	long long min(int a,int b,int k,int l,int r)const{
		if(r<=a || b<=l)return LLONG_MAX;
		if(a<=l && r<=b){
			return segv[k]+segAdd[k];
		}
		int m=(l+r)/2;
		return segAdd[k]+std::min(min(a,b,2*k+1,l,m),min(a,b,2*k+2,m,r));
	}
public:
	StarrySkyTree(int n=1<<19){
		init(n);
	}
	void init(int n){
		this->n=n;
		segv.assign(2*n-1,0);
		segAdd.assign(2*n-1,0);
	}
	void add(int a,int b,int x){//[a,b)にxを加算
		add(a,b,x,0,0,n);
	}
	long long min(int a,int b)const{//[a,b)の最小値
		return min(a,b,0,0,n);
	}
};



int main(){
	StarrySkyTree sst;
	set<int> s;
	string str;
	int n,q;
	cin>>n>>q>>str;
	rep(i,n){
		if(str[i]=='(')sst.add(i,n,1);
		else{
			sst.add(i,n,-1);
			s.insert(i);
		}
	}
	rep(i,q){
		int p;
		cin>>p;
		p--;
		int lb,ub,ans;
		if(str[p]=='('){
			str[p]=')';
			sst.add(p,n,-2);
			s.insert(p);
			ans=*s.begin();
			str[ans]='(';
			sst.add(ans,n,2);
			s.erase(ans);
			ans++;
		}else{
			str[p]='(';
			sst.add(p,n,2);
			s.erase(p);
			lb=-1;ub=n-1;
			while(ub-lb>1){
				int m=(lb+ub)/2;
				if(sst.min(m,n)>=2)ub=m;
				else lb=m;
			}
			str[ub]=')';
			sst.add(ub,n,-2);
			s.insert(ub);
			ans=ub+1;
		}
		cout<<ans<<endl;
	}
	return 0;
}