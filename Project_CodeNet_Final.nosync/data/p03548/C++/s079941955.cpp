#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double db;
typedef pair<int,int> pii;
typedef vector<int> vi;
#define de(x) cout << #x << "=" << x << endl
#define rep(i,a,b) for(int i=a;i<(b);++i)
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define lb(x) (x&-(x))
const int N = 101010;

int main(){

	int x,y,z;
	cin>>x>>y>>z;
	x-=z;
	cout<<x/(y+z)<<endl;



    return 0;
}
