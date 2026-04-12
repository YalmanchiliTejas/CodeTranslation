//yukicoder@cpp14
//author:luckYrat(twitter:@luckYrat_)
//<ここに一言>

//せんげん！
#include <iostream>

#include <cmath>
#include <algorithm>
#include <iomanip>

#include <string>
#include <vector>
#include <set>
#include <stack>
#include <queue>
#include <map>
#include <bitset>

#include <cctype>
#include <utility>
#include <climits>


//なまえくーかん！
using namespace std;
using ll = long long;
using P = pair<ll,ll>;

//てーすう！
const int mod = 1000000007;
const int inf = (1<<30)-1;
const ll linf = (1LL<<62LL)-1;
const double EPS = (1e-10);

//でふぁいん！
#define anyfill(n,s) setw(n) << setfill(s)
#define loop(s) for(int i = 0; s > i; i++)
#define rep(i,q) for(int i = 0; (q) > i; i++)
#define repp(i,n,q) for(int i = n; (q) > i; i++)
#define dep(i,q) for(int i = (q); 0 < i; i--)

//みじかく！
#define pb push_back
#define fir first
#define scn second
#define ednl endl

//いぇすのー！
#define YesNo(a) (a?"Yes":"No")
#define YESNO(a) (a?"YES":"NO")
#define yesno(a) (a?"yes":"no")

//きんぼーnほーこー！！
P ar4[4] = {{0,1},{0,-1},{1,0},{-1,0}};
P ar8[8] = {{-1,-1},{-1,0},{-1,1},{0,-1},{0,1},{1,-1},{1,0},{1,1}};
/*
確認ポイント
cout << fixed << setprecision(n) << 小数計算//n桁の小数表記になる

計算量は変わらないが楽できるシリーズ
min(max)_element(iter,iter)で一番小さい(大きい)値のポインタが帰ってくる
count(iter,iter,int)でintがiterからiterの間にいくつあったかを取得できる
*/
template <typename T>
T gcd(T a,T b){
  if(a%b==0)return b;
  else return gcd(b,a%b);
}
template <typename T>
T lcm(T a,T b){
  return a/gcd(a,b)*b;
}
int dp[200][200];
struct z{
	int a,b,c;
};
__attribute__((constructor))
void initial() {
 cin.tie(0);
 ios::sync_with_stdio(false);
}
int main(){
	int n;cin>>n;
	vector<int> A(n);
	for(int i = 0; n > i; i++){
		cin>>A[i];
	}
	sort(A.begin(),A.end());
	vector<int> Y;
	for(int i = 1; A[n-1] >= i*i; i++){
		if(!(A[n-1]%i)){
			Y.push_back(i);
			if(i*i!=A[n-1])Y.push_back(A[n-1]/i);
		}
	}
	sort(Y.begin(),Y.end());
	int ans = 0;
	for(int i = 0; n > i; i++){
		ans += *lower_bound(Y.begin(),Y.end(),A[i])-A[i];
	}
	cout << ans << endl;

}

