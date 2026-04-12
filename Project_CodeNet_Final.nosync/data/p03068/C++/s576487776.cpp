#include<bits/stdc++.h>
using namespace std;
typedef signed long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
//vvi(n, vector<int>(m, -1))
 
#define REP(i,a,b) for(i=a;i<b;i++)
#define rep(i,n) REP(i,0,n)
#define all(a) (a).begin(), (a).end()
#define out(x) cout << (x) << endl;

int main(){
	int i,j,k,n,m,l,f,x,y,z; string s;
	cin >> n >> s >> k;

	rep(i, n){
		if(s[i] != s[k-1]){
			cout << '*';
		}else{
			cout << s[i];
		}
	}
}