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

int L;
string S,T;
int a,b;

int main(){
	cin >> L;
	cin >> S >> T;
	if(S+T > T+S) swap(S,T);
	a = S.size();
	b = T.size();
	repm(i,L/a,-1){
		if((L-a*i)%b == 0){
			repp(k,0,i) cout << S;
			repp(k,0,(L-a*i)/b) cout << T;
			cout << endl;
			break;
		}
	}
	return 0;
}
