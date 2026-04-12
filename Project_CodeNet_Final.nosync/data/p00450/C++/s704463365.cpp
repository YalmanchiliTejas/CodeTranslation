#include <bits/stdc++.h>
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define RFOR(i,a,b) for(int i=(b) - 1;i>=(a);i--)
#define REP(i,n) for(int i=0;i<(n);i++)
#define RREP(i,n) for(int i=n-1;i>=0;i--)

#define PB push_back
#define INF (1<<29)
#define ALL(a) (a).begin(),(a).end()
#define RALL(a) (a).rbegin(),(a).rend()
#define CLR(a) memset(a,0,sizeof(a))
const int dx[] = {-1,0,0,1},dy[] = {0,1,-1,0};

typedef long long int ll;

using namespace std;

int main(){
    while(true){
	int n;
	cin >> n;
	if(n == 0) break;
	vector<int> v(n);
	vector<int> coor;
	REP(i,n) cin >> v[i];

	int head = v[0];
	coor.PB(0);
	FOR(i,1,n){
	    if(i % 2 == 0){
		if(head != v[i]){
		    coor.PB(i);
		    head = v[i];
		}
	    }else{
		if(head != v[i]){
		    if(coor.size() > 1)
			coor.erase(coor.end()-1);
		    head = v[i];
		}
	    }
	}
	/*
	cout << "==coord==" << endl;
	REP(i,coor.size()) cout << coor[i] << endl;
	cout << "==end==" << endl;
	*/
	int ans = 0;
	int s = n;
	RREP(i,coor.size()){
	    if(head % 2 == 0){
		ans += s - coor[i];
	    }
	    head = (head+1)%2;
	    s = coor[i];
	}
	cout << ans << endl;
    }
    return 0;
}