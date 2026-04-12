#include<string>
#include<deque>
#include<queue>
#include<vector>
#include<algorithm>
#include<iostream>
#include<set>
#include<cmath>
#include<tuple>
#include<map>
#include<functional>
using namespace std;
typedef long long int llint;
typedef bool izryt;
#define mp make_pair
#define mt make_tuple
#define pub push_back
#define puf push_front
#define pob pop_back
#define pof pop_front
#define fir first
#define sec second
#define res resize
#define ins insert
#define era erase
const int big=1e9;
const int mod=1e9 + 7;
int main(void){
	llint r,c,n,i,j,q,w;cin>>n;
	vector<tuple<llint,llint,llint>> road(2*(n-1));
	vector<pair<llint,llint>>xs(n);
	vector<pair<llint,llint>>ys(n);
	vector<llint> go(n);
	vector<llint> ufr(n);
	for(i=0;i<n;i++){
		cin>>q>>w;
		xs[i]=mp(q,i);
		ys[i]=mp(w,i);
	}
	sort(xs.begin(),xs.end());
	sort(ys.begin(),ys.end());
	for(i=0;i<n-1;i++){
		road[i]=mt(xs[i+1].fir-xs[i].fir,xs[i].sec,xs[i+1].sec);
	}
	for(i=0;i<n-1;i++){
		road[i+n-1]=mt(ys[i+1].fir-ys[i].fir,ys[i].sec,ys[i+1].sec);
	}
	sort(road.begin(),road.end());
	for(i=0;i<n;i++){go[i]=i;}
	llint ren=n,ans=0;
	for(i=0;ren>1;i++){
		llint tqg=get<1>(road[i]);
		llint twg=get<2>(road[i]);
		while(tqg!=go[tqg]){tqg=go[tqg];}
		while(twg!=go[twg]){twg=go[twg];}
		if(tqg==twg){continue;}
		if(ufr[tqg]<ufr[twg]){swap(tqg,twg);}
		go[twg]=tqg;
		if(ufr[tqg]==ufr[twg]){ufr[tqg]++;}
		ans+=get<0>(road[i]);
		ren--;
	}
	cout<<ans<<endl;
	return 0;
}