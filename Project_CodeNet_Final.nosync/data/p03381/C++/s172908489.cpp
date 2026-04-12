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

const int MC = 2e5 + 3;
int N;
int X[MC],a[MC];

int main(){
	cin >> N;
	repp(i,0,N){
		cin >> X[i];
		a[i] = X[i];
	}
	sort(a,a+N);
	repp(i,0,N) cout << (a[N/2] > X[i] ? a[N/2] : a[N/2-1]) << endl;
	return 0;
}
