#include <bits/stdc++.h>

using namespace std;
using ll =long long;

#define SORT(a) sort((a).begin(),(a).end())
#define rSORT(a) reverse((a).begin(),(a).end())
#define For(i, a, b)    for(int i = (a) ; i < (b) ; ++i)
#define rep(i, n)       For(i, 0, n)
#define debug(x)  cout << #x << " = " << (x) << endl;
void coY() {cout <<"Yes"<<endl;}
void coN(){cout <<"No"<<endl;}

template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
const ll INF = 1LL << 60;

//Write From this Line
vector<int> G[10];
int main()
{
	int n , m ;
	cin >>  n >> m ;
	rep(i,m){
		int a , b ;
		cin >>  a >> b ;
		--a , --b ;
		G[a].push_back(b);
		G[b].push_back(a);
	}
	vector<int> root(n-1);
	rep(i,n-1){
		root[i] = i +1 ;
	}
	ll ans = 0 ;

	do{
		//今見てるrootの順序ですべての頂点を探索できるか。
		int start = 0;
		int count = 0;
		while(1){
			bool no_root = false ;
			for(int i = 0 ; i < G[start].size() ; i++){
				if(G[start][i] == root[count]){
					//ok
					start = root[count];
					count ++ ;
					break;
				}
				if(i==G[start].size()-1){
					no_root = true ;
				}
			}
			if(count == n -1 ){
				ans ++ ; 
				count = 0 ;
				start = 0 ;
				break ;
			}
			if(no_root){
				count = 0 ;
				start = 0;
				break;
			}
		}
	} while (next_permutation(root.begin(),root.end()));
	cout << ans << endl;
}
