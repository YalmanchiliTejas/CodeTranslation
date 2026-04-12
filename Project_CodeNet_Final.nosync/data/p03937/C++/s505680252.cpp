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

int main(void){
	int h, w; scanf("%d%d", &h, &w);
	char s[h][w];
	rep(i, h) rep(j, w) cin >> s[i][j];
	
	pair<int, int> q = mp(0, 0);
	
	while(true){
		s[q.fir][q.sec] = '.';
		if(q == mp(h-1, w-1)) break;
		
		if(q.fir != h-1 && s[q.fir+1][q.sec] == '#'){
			q = mp(q.fir+1, q.sec);
		}else if(q.sec != w-1 && s[q.fir][q.sec+1] == '#'){
			q = mp(q.fir, q.sec+1);
		}else{
			cout << "Impossible" << endl;
			return 0;
		}
	}
		
	rep(i, h) rep(j, w) if(s[i][j] == '#'){
		cout << "Impossible" << endl;
		return 0;
	}
	
	cout << "Possible" << endl;
	return 0;
}