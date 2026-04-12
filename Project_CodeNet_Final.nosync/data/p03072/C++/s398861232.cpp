/**********************************
	author:  mariogzsl
**********************************/

#include <bits/stdc++.h>

#define FOR(i,a,b) for(int i=a;i<b;i++)
#define ROF(i,b,a) for(int i=b-1;i>=a;i--)
#define f first
#define s second
#define puts(x) cout<<x<<endl
using namespace std;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef long long ll;
int gcd(int a, int b){return (b==0)?a:gcd(b,a%b);}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int N;
	int m=-1;
	int c, ans=0;
	cin>>N;
	FOR(i,0,N){
		cin>>c;
		if(c>=m)ans++;
		m=max(m, c);
	}
	cout<<ans<<endl;
	return 0;
}
