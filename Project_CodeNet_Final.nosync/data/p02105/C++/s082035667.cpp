#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>
#include <iostream>
#include <string>
#include <map>
#include <set>
#include <functional>
#include <iostream>
#define MOD 1000000007LL
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;

int n;
int n_;
P cnt[6];
ll a,b;
vector<P> xy[5];
vector<P> one;
vector<P> two;
vector<ll> Bval;
int dat[1<<22];

void add(int k,int a){
	k+=n_-1;
	dat[k]+=a;
	while(k>0){
		k=(k-1)/2;
		dat[k]=dat[k*2+1]+dat[k*2+2];
	}
}

int query(int a,int b,int k=0,int l=0,int r=n_){
	if(r<=a || b<=l)return 0;
	if(a<=l && r<=b)return dat[k];
	int vl=query(a,b,k*2+1,l,(l+r)/2);
	int vr=query(a,b,k*2+2,(l+r)/2,r);
	return vl+vr;
}

int main(void){
	scanf("%d%lld%lld",&n,&a,&b);
	for(int i=0;i<n;i++){
		ll x,y;
		int t;
		scanf("%d%lld%lld",&t,&x,&y);
		t--;
		xy[t].push_back(P(x,y));
		cnt[t].first++;
	}
	for(int i=0;i<5;i++){
		cnt[i].second=i;
		xy[i].push_back(P(0,0));
	}
	sort(cnt,cnt+5);
	for(int i=0;i<xy[cnt[0].second].size();i++){
		for(int j=0;j<xy[cnt[1].second].size();j++){
			for(int k=0;k<xy[cnt[2].second].size();k++){
				ll xx=xy[cnt[0].second][i].first+xy[cnt[1].second][j].first+xy[cnt[2].second][k].first;
				ll yy=xy[cnt[0].second][i].second+xy[cnt[1].second][j].second+xy[cnt[2].second][k].second;
				one.push_back(P(xx,yy));
				Bval.push_back(yy);
			}
		}
	}
	sort(one.begin(),one.end());
	reverse(one.begin(),one.end());
	sort(Bval.begin(),Bval.end());
	Bval.erase(unique(Bval.begin(),Bval.end()),Bval.end());
	for(int i=0;i<one.size();i++){
		one[i].second=lower_bound(Bval.begin(),Bval.end(),one[i].second)-Bval.begin();
	}
	for(int i=0;i<xy[cnt[3].second].size();i++){
		for(int j=0;j<xy[cnt[4].second].size();j++){
			ll xx=xy[cnt[3].second][i].first+xy[cnt[4].second][j].first;
			ll yy=xy[cnt[3].second][i].second+xy[cnt[4].second][j].second;
			two.push_back(P(xx,yy));
		}
	}
	sort(two.begin(),two.end());
	n_=1;
	while(n_<one.size())n_*=2;
	int l=0,r=0;
	bool flag=false;
	for(int i=0;i<two.size();i++){
		while(l<one.size() && one[l].first+two[i].first>=a){
			add(one[l].second,1);
			l++;
		}
		while(l>r && one[r].first+two[i].first>b){
			add(one[r].second,-1);
			r++;
		}
		int al=lower_bound(Bval.begin(),Bval.end(),a-two[i].second)-Bval.begin();
		int ar=upper_bound(Bval.begin(),Bval.end(),b-two[i].second)-Bval.begin();
		if(query(al,ar)>0)flag=true;
	}
	printf("%s\n",flag?"Yes":"No");
	return 0;
}