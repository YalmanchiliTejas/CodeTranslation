#include<cstdio>
#include<cstring>
#include<vector>
#include<queue>
#include<algorithm>
#include<cmath>
#include<climits>
#include<string>
#include<set>
#include<map>
#include<iostream>
using namespace std;
#define rep(i,n) for(int i = 0;i<((int)(n));i++)
#define reg(i,a,b) for(int i = ((int)(a));i<=((int)(b));i++)
#define irep(i,n) for(int i = ((int)(n)-1);i>=0;i--)
#define ireg(i,a,b) for(int i = ((int)(b)-1);i>=((int)(a));i--)
typedef long long int lli;
typedef pair<int, int> mp;
#define fir first
#define sec second
#define IINF INT_MAX
#define LINF LLONG_MAX
#define eprintf(...) fprintf(stderr,__VA_ARGS__)
#define pque(type) priority_queue<type,vector<type>,greater<type> >
#define memst(a,b) memset(a,b,sizeof(a))

#define piv(a,v) pair<int,vector<int> >(a,v)

int main(void){
	int n, m;
	cin >> n >> m;
	vector<int> v[n]; // 1→0
	rep(i, m){
		int ts, tt;
		cin >> ts >> tt;
		v[ts-1].push_back(tt-1);
		v[tt-1].push_back(ts-1);
	}
	
	int ans = 0;
	
	queue < pair< int, vector<int> > > q;
	vector<int> tv; tv.push_back(0);
	q.push(piv(0, tv));
	
	while(true){
		pair< int, vector<int> > t = q.front(); q.pop();
		if(t.sec.size() == n) ans++;
		else{
			rep(i, v[t.fir].size()){
				if(find(t.sec.begin(), t.sec.end(), v[t.fir][i]) == t.sec.end()){
					pair< int, vector<int> > s = t;
					s.fir = v[t.fir][i];
					s.sec.push_back(s.fir);
					q.push(s);
				}
			}
		}
		
		if(q.size()==0) break;
	}
	
	cout << ans << endl;
	
	return 0;
}