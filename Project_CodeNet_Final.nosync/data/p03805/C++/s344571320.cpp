#include <bits/stdc++.h>
using namespace std;
using Graph = vector<vector<int>>;

typedef long long ll;
typedef long double ld;

#define REP(i,a,n) for(int (i)=(a); (i)<(int)(n); (i)++)
#define rep(i,n) REP(i,0,n)
#define vec vector 

const int INF = 2e9;
const ll large_P = 1e9 + 7;


int main() {
	int N, M;
	cin >> N >> M;

	vector<int> a(M), b(M);
	rep(i, M) cin >> a.at(i) >> b.at(i);
	rep(i, M) a.at(i)--;
	rep(i, M) b.at(i)--;

	Graph g(N);
	rep(i, M) g.at(a.at(i)).push_back(b.at(i));
	rep(i, M) g.at(b.at(i)).push_back(a.at(i));
    
    rep(i, N) sort(g.at(i).begin(), g.at(i).end());


	vector<int> c(N);
	rep(i, N) c.at(i) = i;

	int res = 0;
	//if (M >= 2){
		do {
			bool ok = false;
			for(int i = 0; i < N-1; i++){
              ok = false;
              if(!g.at(c.at(i)).empty()){
                if(binary_search (g.at(c.at(i)).begin(), g.at(c.at(i)).end(), c.at(i + 1))) ok =true;
              }
		      if (!ok) break;
			}
			if(ok) res++;

		} while(next_permutation(c.begin() + 1, c.end()));
	//}
	//else if (M == 1 && N == 2) res = 1;
	//else res = 0;

	
	cout << res << endl;


 }