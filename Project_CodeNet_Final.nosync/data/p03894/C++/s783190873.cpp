#include <bits/stdc++.h>
using namespace std;

#define FOR(i,l,r) for(int i = (l);i < (r);i++)
#define ALL(x) (x).begin(),(x).end()
template<typename T> bool chmax(T& a,const T& b){return a < b ? (a = b,true) : false;}
template<typename T> bool chmin(T& a,const T& b){return b < a ? (a = b,true) : false;}
typedef long long ll;

int N,Q;
bool P [100001];

bool in_range(int x)
{
	return x >= 1 && x <= N;
}

int main()
{
	scanf("%d%d",&N,&Q);
	vector<int> A(N + 1);
	for(int i = 1;i <= N;i++){
		A [i] = i;
	}
	int ans = 2;
	P [1] = true;
	P [2] = true;

	FOR(i,0,Q){
		int x,y;
		scanf("%d%d",&x,&y);
		swap(A [x],A [y]);
		for(int i = -1;i <= 1;i++) if(in_range(x + i) && A [x + i] == 1){
			for(int j = -1;j <= 1;j++) if(in_range(x + i + j) && P [A [x + i + j]] == false){
				ans++;
				P [A [x + i + j]] = true;
			}
		}
		for(int i = -1;i <= 1;i++) if(in_range(y + i) && A [y + i] == 1){
			for(int j = -1;j <= 1;j++) if(in_range(y + i + j) && P [A [y + i + j]] == false){
				ans++;
				P [A [y + i + j]] = true;
			}
		}
	}

	printf("%d\n",ans);

	return 0;
}
