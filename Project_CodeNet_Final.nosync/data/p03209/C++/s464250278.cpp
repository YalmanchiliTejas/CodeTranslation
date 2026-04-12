#include <bits/stdc++.h>
using namespace std;
#define FOR(i,o,n) for(long long i = o;i<n;i++)
#define oneforall ios::sync_with_stdio(false);cin.tie(0);
#define all(v) (v).begin(),(v).end()
#define ini(...) int __VA_ARGS__; in(__VA_ARGS__)
#define inl(...) long long __VA_ARGS__; in(__VA_ARGS__)
#define ins(...) string __VA_ARGS__; in(__VA_ARGS__)
#define int long long 
const long long INF=1e18;
void in(){} template <typename T,class... U> void in(T &t,U &...u){ cin >> t; in(u...);}
void out(){cout << "\n";} template <typename T,class... U> void out(const T &t,const U &...u){ cout << t; if(sizeof...(u)) cout << " "; out(u...);}
typedef vector<int> vi;
typedef vector<long long> vl;
typedef long long ll;
typedef vector<pair<long, long > > vpll;
typedef vector<pair<int, int > > vpii;



int32_t main() {
	oneforall
	oneforall
	oneforall
	oneforall
	oneforall
	oneforall
	oneforall
	oneforall
	oneforall
	oneforall
	oneforall
	oneforall
	oneforall
	oneforall
	

	
	ini(n);
	ini(k);
	int h[51];
	int p[51];
	h[0] = 1;
	p[0] = 1;
	FOR(i,1,51){
		h[i] = 3+2*h[i-1];
		p[i] = 1+2*p[i-1];
	}
	int rick = 0;
	while(n>0 and k>0){
		if(k>=2+2*h[n-1]){
			rick+=1+2*p[n-1];
			k = 0;
			break;
		}
		else if (k>=h[n-1]+2){
			rick+=1+p[n-1];
			k-=2+h[n-1];
		}
		else k--;
		n--;
	}
	if(k)rick++;
	out(rick);







	return 0;
}
