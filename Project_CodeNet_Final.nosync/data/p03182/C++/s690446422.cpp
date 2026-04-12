/*
AuThOr Gwj
*/
#include<bits/stdc++.h>
#define rb(a,b,c) for(int a=b;a<=c;++a)
#define rl(a,b,c) for(int a=b;a>=c;--a)
#define LL long long
#define IT iterator
#define PB push_back
#define II(a,b) make_pair(a,b)
#define FIR first
#define SEC second
#define FREO freopen("check.out","w",stdout)
#define rep(a,b) for(int a=0;a<b;++a)
#define KEEP while(1)
#define SRAND mt19937 rng(chrono::steady_clock::now().time_since_epoch().count())
#define random(a) rng()%a
#define ALL(a) a.begin(),a.end()
#define POB pop_back
#define ff fflush(stdout)
#define fastio ios::sync_with_stdio(false)
#define debug_pair(A) cerr<<A.FIR<<" "<<A.SEC<<endl;
using namespace std;
const LL INF=2e15;
typedef pair<int,int> mp;
typedef pair<mp,mp> superpair;
LL Add[8*200000],tree[8*200000];
const int MAXN=262144;
LL query(int a,int b,int now=1,int l=1,int r=MAXN+1){
	if(r<=a||l>=b){
		return -INF;		
	}
	if(r<=b&&l>=a){
		return tree[now]+Add[now];
	}
	int mid=(l+r)>>1;
	return max(query(a,b,now<<1,l,mid),query(a,b,(now<<1)+1,mid,r))+Add[now];
} 
LL add(int a,int b,LL val,int now=1,int l=1,int r=MAXN+1){
	if(r<=a||l>=b){
		return tree[now]+Add[now];	
	}
	if(r<=b&&l>=a){
		Add[now]+=val;
		return tree[now]+Add[now];
	}
	int mid=(l+r)>>1;
	return Add[now]+(tree[now]=max(add(a,b,val,now<<1,l,mid),add(a,b,val,(now<<1)+1,mid,r))); 
}
vector<mp> v[200000+20];
int main(){
	fastio;
	int n,m;
	cin>>n>>m;
	rb(i,1,m){
		int li,ri,ai;
		cin>>li>>ri>>ai;
		v[ri].PB(II(li,ai));
	}
	rb(i,1,n){
		sort(ALL(v[i]));
	}
	rb(r,1,n){
		LL tmp=query(1,r+1);
		LL sum=0;
		int las=1;
		for(auto it:v[r]){
			if(it.FIR==las){
			}
			else{
				add(las,it.FIR,sum);
			}	
			sum+=it.SEC;
			las=it.FIR;
		}
		if(las!=r){
			add(las,r,sum);
		}
		add(r,r+1,tmp+sum);
		
	}
	cout<<query(1,MAXN+1)<<endl;
//	add(1,2,-10);
//	add(1,2,0);
//	add(2,3,-30);
//	add(1,3,100);
//	add(3,4,70);
//	cout<<query(1,MAXN+1)<<endl;
	return 0;
}
