#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define P pair<int,int>
#define FOR(I,A,B) for(int I = (A); I < (B); ++I)
#define FORR(I,A,B) for(int I = ((B)-1); I >= (A); --I)
#define TO(x,t,f) ((x)?(t):(f))
#define SORT(x) (sort(x.begin(),x.end())) // 0 2 2 3 4 5 8 9
#define REV(x) (reverse(x.begin(),x.end())) //reverse
int gcd(int a,int b){if(a<b)swap(a,b);if(a%b==0)return b;return gcd(b,a%b);}
int lcm(int a,int b){int c=gcd(a,b);return ((a/c)*(b/c)*c);}//saisyo kobaisu
#define NEXTP(x) next_permutation(x.begin(),x.end())
const ll INF=1e18+7;
const ll MOD=1e9+7;
#define pri(a) cout << (a) << endl


int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	if(n==7||n==5||n==3){
		cout << "YES" << endl;
	}else{
		cout << "NO" << endl;
	}
}