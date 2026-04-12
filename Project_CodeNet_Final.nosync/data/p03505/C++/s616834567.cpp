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

LL K,A,B;

int main(){
	cin >> K >> A >> B;
	if(K <= A) cout << 1 << endl;
	else if(A <= B) cout << -1 << endl;
	else if(A-B==1) cout << 1+(K-A)*2 << endl;
	else cout << 1+(K-B)/(A-B)*2 << endl;
	return 0;
}
