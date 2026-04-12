#include <bits/stdc++.h>
//#include <boost/multiprecision/cpp_int.hpp>
using namespace std;
//using namespace boost::multiprecision;

typedef pair<int,int> pii;
typedef long long ll;
typedef vector<int> vi;

#define rep(i,j) for(int i=0;i<(j);i++)
#define reps(i,j,k) for(int i=j;i<k;i++)
#define in(i,j,k) ((i)>=(j)&&(i)<=(k))
#define INF (1<<28)
#define pb push_back
#define fs first
#define sc second

const char dx[]={0,1,0,-1},dy[]={1,0,-1,0};
template<class T>
ostream &operator<<(ostream &out, const vector<T> &v){
	out << "{";
	rep(i,v.size()) out << v[i] << ", " ;
	return out << "}" << endl;
}
template<class S,class T>
ostream &operator<<(ostream &out, const pair<S,T> p){
	return out << "(" << p.fs << ", " << p.sc << ")";
}
/*cpp_int sum( cpp_int N )
{
	if( N == 0 ) return 1;
	else return N * sum( N - 1 );
}*/
int main(){
	int n;
	cin >> n;
	vector<pii> a(n);
	rep(i,n){
		int t;
		cin >> t;
		a[i] = pii(i%2==1 ^ n%2 ? -i : i, t);
	}
	sort(a.begin(), a.end());
	rep(i,n) cout << a[i].sc << endl;
	return 0;
}
