/**********************************************************
 * ×÷??£?zxf
 * ????£?2017/8/10
 * ±???£?Miscalculation
 * ????£?Gym 100803B
 * ×??????¨£?
 * ????£?
 * Time used£?
 * Memory used£?
 **********************************************************/
#include <algorithm>
#include <bitset>
#include <cassert>
#include <cctype>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <fstream>
#include <functional>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <vector>
#define LL long long
#define pb push_back
#define pob pop_back
#define mp make_pair
#define FILL(a,v) memset((void*)a,v,sizeof(a))
#define FILL0(a) FILL(a,0)
#define FILL1(a) FILL(a,-1)
#define ALL(a) (a).begin(),(a).end()
#define Inf 1e9
#define Mod 1000000007
#define foreach(it,x) for(typeof(x.begin()) it=x.begin();it!=x.end();it++)
#define FOR(i,x) for(int i=0;i<x;i++)
#define RFOR(i,x) for(int i=x-1;i>=0;i--)
#define FFOR(i,a,b) for(int i=a;i<b;i++)
#define FRFOR(i,a,b) for(int i=a-1;i>=b;i--)
#define SZ(a) ((int)(a).size())
#define FI first
#define SE second
#define OVER(a) return puts(a),0
#define fastio ios::sync_with_stdio(0)
#define filei(f) freopen(f,"r",stdin)
#define fileo(f) freopen(f,"w",stdout)
using namespace std;
typedef pair<int,int> pii;
typedef unsigned long long UINT;
typedef unsigned int Uint;
typedef long long INT;
typedef pair<INT,INT> PII;
typedef stringstream sst;
typedef istringstream iss;
typedef vector<int> vint;
typedef vector<INT> VINT;
typedef vector<pii> vpii;
typedef vector<PII> VPII;
typedef priority_queue<int> pqi;
typedef priority_queue<INT> PQI;
typedef priority_queue<pii> pqp;
typedef priority_queue<PII> PQP;
typedef priority_queue<int,vint,greater<int> > xqi;
typedef priority_queue<INT,VINT,greater<INT> > XQI;
typedef priority_queue<pii,vpii,greater<pii> > xqp;
typedef priority_queue<PII,VPII,greater<PII> > XQP;

vector<pair<INT,INT> > cal,cal2;
string sns;
INT ans1,ans2,ans;

int main()
{
	cin>>sns;
	INT a=0,b=0;
	for(int i=0;i<SZ(sns);i++)
		if(isdigit(sns[i]))
			a=a*10+sns[i]-'0';
		else
		{
			if(sns[i]=='+') b=1;
			else b=2;
			cal.push_back(mp(a,b));
			a=0;
		}
	cal.push_back(mp(a,1));
	a=1;
	int chenging=0;
	for(int i=0;i<SZ(cal);i++)
	{
		if(chenging)a*=cal[i].first;
		if(chenging&&cal[i].second==1)
		{
			cal2.push_back(mp(a,1));
			chenging=0;
		}
		else if(!chenging&&cal[i].second==2)
			chenging=1,a=cal[i].first;
		else if(!chenging)cal2.push_back(mp(cal[i].first,1));
	}
	ans1=0;
	for(int i=0;i<SZ(cal2);i++)
	{
		ans1+=cal2[i].first;
	}
	ans2=cal[0].first;
	for(int i=0;i<SZ(cal)-1;i++)
	{
		if(cal[i].second==1)ans2+=cal[i+1].first;
		else ans2*=cal[i+1].first;
	}
	cin>>ans;
	if(ans==ans1&&ans==ans2)OVER("U");
	if(ans==ans1)OVER("M");
	if(ans==ans2)OVER("L");
	OVER("I");
}