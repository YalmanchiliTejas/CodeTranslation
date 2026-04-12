/*
*/

#pragma GCC optimize("O3")
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

#define eps 1e-11
#define M_PI 3.141592653589793
#define bs 1000000007
#define bsize 512

#define ldouble long double
using namespace std;

long long INF = 1e9;

const int N = 300031;

vector<pair<int,int> > by_x,by_y;
int n;
int x[N],y[N];
vector<pair<int,pair<int,int> > > edges;
int w[N];

int get(int x)
{
	if (x==w[x])
		return x;
	return w[x]=get(w[x]);
}

void merge(int a,int b)
{
	a=get(a);
	b=get(b);
	w[a]=b;
}

long long ans;

void add_edge(pair<int,int> p1,pair<int,int> p2){
	edges.push_back(make_pair(abs(p1.first-p2.first),make_pair(p1.second,p2.second)));
}

int main(){
	//freopen("tree.in","r",stdin);
	//freopen("tree.out","w",stdout);
	//freopen("input.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	ios_base::sync_with_stdio(0);
	//cin.tie(0);

	cin>>n;
	for (int i=1;i<=n;i++)
	{
		cin>>x[i]>>y[i];
		by_x.push_back(make_pair(x[i],i));
		by_y.push_back(make_pair(y[i],i));
	}

	sort(by_x.begin(),by_x.end());
	sort(by_y.begin(),by_y.end());
	for (int i=1;i<=n;i++)
	{
		w[i]=i;
	}
	edges.clear();
	for (int i=1;i<by_x.size();i++)
	{
		add_edge(by_x[i-1],by_x[i]);
	}
	for (int i=1;i<by_y.size();i++)
	{
		add_edge(by_y[i-1],by_y[i]);
	}

	sort(edges.begin(),edges.end());
	for (int i=0;i<edges.size();i++)
	{
		int v1=edges[i].second.first;
		int v2=edges[i].second.second;
		v1=get(v1);
		v2=get(v2);
		if (v1==v2)
		{
			continue;
		}
		ans+=edges[i].first;
		merge(v1,v2);
	}

	cout<<ans<<endl;

	cin.get(); cin.get();
	return 0;
}
