#include <bits/stdc++.h>
using namespace std;

#define FOR(i,l,r) for(int i = (l);i < (r);i++)
#define ALL(x) (x).begin(),(x).end()
template<typename T> bool chmax(T& a,const T& b){return a < b ? (a = b,true) : false;}
template<typename T> bool chmin(T& a,const T& b){return b < a ? (a = b,true) : false;}
typedef long long ll;

int H,W;

int main()
{
	cin.tie(0);
	ios::sync_with_stdio(false);

	cin >> H >> W;
	vector<string> board(H);
	int cnt = 0;
	FOR(i,0,H){
		cin >> board [i];
		cnt += count(ALL(board [i]),'#');
	}
	if(cnt == H + W - 1){
		cout << "Possible" << endl;
	}
	else{
		cout << "Impossible" << endl;
	}
	

	return 0;
}
