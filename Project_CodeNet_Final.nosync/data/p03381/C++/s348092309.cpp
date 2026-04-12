#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef pair<int , int> P2;
typedef pair<pair<int , int> , int> P3;
typedef pair<pair<int , int> , pair<int , int> > P4;
#define PB(a) push_back(a)
#define MP(a , b) make_pair((a) , (b))
#define M3P(a , b , c) make_pair(make_pair((a) , (b)) , (c))
#define M4P(a , b , c , d) make_pair(make_pair((a) , (b)) , make_pair((c) , (d)))
#define repp(i,a,b) for(int i = (int)(a) ; i < (int)(b) ; ++i)
#define repm(i,a,b) for(int i = (int)(a) ; i > (int)(b) ; --i)

const int MC = 200010;
int N;
vector<int> X;
vector<int> s,r;

int main(){
	cin >> N;
	X.resize(N);
	s.resize(N);
	r.resize(N);
	repp(i,0,N){
		cin >> X[i];
		s[i] = i;
	}
	sort(s.begin(),s.end(),[&](const int &a , const int &b){return X[a] < X[b];});
	repp(i,0,N) r[s[i]] = i;
	repp(i,0,N) cout << X[s[r[i]<N/2?N/2:(N/2-1)]] << endl;
	return 0;
}
