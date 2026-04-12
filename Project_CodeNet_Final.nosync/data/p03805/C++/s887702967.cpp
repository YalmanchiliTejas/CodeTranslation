//高知能系Vtuberの高井茅乃です。
//Twitter: https://twitter.com/takaichino
//YouTube: https://www.youtube.com/channel/UCTOxnI3eOI_o1HRgzq-LEZw

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define INTINF 1999999999
#define REP(i,n) for(int i=0;i<n;i++)
#define REP1(i,n) for(int i=1;i<=n;i++)
#define MODA 1000000007 

int main() {
	ll ans = 0;
	int tmp;

	//隣接テーブルをつくる
	int n,v; //葉と枝の数
	cin >> n >> v; 
	int tab[n+1][n+1] = {};
	REP(i,v){
		int sta, goa;
		cin >> sta >> goa;
		tab[sta][goa]++;
		tab[goa][sta]++;
	}
	//
	vector<int > vc;
	REP1(i, n) vc.push_back(i);
	bool ch;
	do{
		ch = true;
		REP(i, n-1) if(tab[vc[i]][vc[i+1]]==0) ch = false;
		if(ch) ans++;
	}while(next_permutation(vc.begin()+1, vc.end()));
	cout << ans << endl;
}