/*
*/

//#pragma GCC optimize("O3")
#define _CRT_SECURE_NO_WARNINGS
#include <fstream>
#include <iostream>
#include <string>
#include <complex>
#include <math.h>
#include <set>
#include <vector>
#include <map>
#include <queue>
#include <stdio.h>
#include <stack>
#include <algorithm>
#include <list>
#include <ctime>

#include <memory.h>
#include <assert.h>

#define y0 sdkfaslhagaklsldk

#define y1 aasdfasdfasdf
#define yn askfhwqriuperikldjk
#define j1 assdgsdgasghsf
#define tm sdfjahlfasfh
#define lr asgasgash
#define norm asdfasdgasdgsd
#define have adsgagshdshfhds
#define ends asdgahhfdsfshdshfd

#define eps 1e-8
#define M_PI 3.141592653589793
#define bsize 512

#define ldouble long double
using namespace std;

#define bs 1000000007

const int N = 600031;

int n,m,S,T,a[N],b[N],len[N];
pair<long long, long long> d[N];
pair<long long, long long> MD[2][N];
vector<int> g[N];

void normalize(long long &x){
	x%=bs;
	if (x<0)
		x+=bs;
}

set<pair<long long, long long> > ss;
set<pair<long long, long long> >::iterator it;

void run_solver(int v){
	for (int i=1;i<=n;i++){
		d[i]=make_pair(1e18,1e18);
	}
	d[v]=make_pair(0,1);

	ss.clear();

	for (int i=1;i<=n;i++){
		ss.insert(make_pair(d[i].first,i+0ll));
	}

	while (ss.size()){
		it=ss.begin();
		pair<long long, long long> p=(*it);
		ss.erase(it);
		int qv=p.second;
		for (int i=0;i<g[qv].size();i++){
			long long id=g[qv][i];
			long long to=a[id]+b[id]-qv;
			long long new_dist=len[id]+d[qv].first;
			if (new_dist>d[to].first)
				continue;
			if (new_dist<d[to].first)
				d[to].second=0;
			d[to].second+=d[qv].second;
			d[to].second%=bs;
			if (new_dist<d[to].first){
				ss.erase(make_pair(d[to].first,to));
				d[to].first=new_dist;
				ss.insert(make_pair(d[to].first,to));
			}
		}
	}
}

int main(){
//	freopen("apache.in","r",stdin);
//	freopen("apache.out","w",stdout);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	ios_base::sync_with_stdio(0);
//	cin.tie(0);

	cin>>n>>m;
	cin>>S>>T;
	for (int i=1;i<=m;i++){
		cin>>a[i]>>b[i]>>len[i];
		g[a[i]].push_back(i);
		g[b[i]].push_back(i);
	}

	run_solver(S);
	for (int i=1;i<=n;i++){
		MD[1][i]=d[i];
	}
	run_solver(T);
	for (int i=1;i<=n;i++){
		MD[2][i]=d[i];
	}

	// take all
	long long ans=MD[2][S].second*MD[2][S].second;
	normalize(ans);

/*	for (int i=1;i<=n;i++){
		cout<<MD[1][i].first<<""
	}*/
	// meet at vertex
	for (int i=1;i<=n;i++){
		if (MD[2][i].first*2==MD[2][S].first&&MD[1][i].first*2==MD[2][S].first){
			long long here=MD[2][i].second*MD[1][i].second;
			here%=bs;
			ans-=here*here%bs;
			normalize(ans);
		}
	}

	// meet on edge
	for (int i=1;i<=m;i++){
		if (MD[1][a[i]].first+MD[2][b[i]].first+len[i]==MD[1][T].first){
		//	cout<<i<<" "<<MD[1][a[i]].first<<"%"<<MD[2][b[i]].first<<" "<<MD[1][T].first<<endl;
			if (MD[1][a[i]].first*2<MD[1][T].first&&MD[2][b[i]].first*2<MD[1][T].first){
				long long P=MD[1][a[i]].second*MD[2][b[i]].second%bs;
			//	cout<<"@@@"<<P<<endl;
				ans-=P*P%bs;
				normalize(ans);
			}
		}
		if (MD[1][b[i]].first+MD[2][a[i]].first+len[i]==MD[1][T].first){
		//	cout<<i<<" "<<MD[1][b[i]].first<<"%"<<MD[2][a[i]].first<<" "<<MD[1][T].first<<endl;
			if (MD[1][b[i]].first*2<MD[1][T].first&&MD[2][a[i]].first*2<MD[1][T].first){
				long long P=MD[1][b[i]].second*MD[2][a[i]].second%bs;
			//	cout<<"@@@"<<P<<endl;
				ans-=P*P%bs;
				normalize(ans);
			}
		}
	}

	cout<<ans<<endl;


//	cin.get(); cin.get();
	return 0;
}
