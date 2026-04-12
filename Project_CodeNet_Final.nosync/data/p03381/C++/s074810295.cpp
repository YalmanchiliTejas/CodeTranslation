#include<bits/stdc++.h>

#define X first
#define Y second
#define eb push_back
#define siz(a) int(a.size())
#define endl "\n"

#define trace2(x, y)             cerr <<#x<<": "<<x<<" | "<<#y<<": "<<y<< endl;
#define trace3(x, y, z)          cerr <<#x<<": "<<x<<" | "<<#y<<": "<<y<<" | "<<#z<<": "<<z<<endl;
#define trace4(a, b, c, d)       cerr <<#a<<": "<<a<<" | "<<#b<<": "<<b<<" | "<<#c<<": "<<c<<" | "<<#d<<": "<<d<<endl;
#define trace5(a, b, c, d, e)    cerr <<#a<<": "<<a<<" | "<<#b<<": "<<b<<" | "<<#c<<": "<<c<<" | "<<#d<<": "<<d<<" | "<<#e<<": "<<e<<endl;

using namespace std;

typedef long long int ll;
typedef vector < int > vi;
typedef vector < ll > vll;

const int mod=1e9+7;
const int maxn=1e6+5;

/*	finding inverse upto n
 * for i in xrange(2, N):
    ifc[i] = -(mod / i) * ifc[mod % i] % mod
 * 
*/
ll power(ll base, ll exp, ll mod){ll res = 1; while(exp){if(exp%2)res*=base;base*=base;res%=mod;base%=mod;exp/=2;}return res;}

//Mai bhut bda chutiya hu :(
//Unfortunately upar jo likha h voh sahi h -_-

int arr[maxn];

int main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);
	//freopen("input.in", "r", stdin);freopen("output.out", "w", stdout);	
	int n, i;
	cin >> n;
	
	vector<pair<int, int> > v;
	
	for(i=1; i<=n; i++){
		cin >> arr[i];
		v.eb({arr[i], i});
	}
	
	sort(v.begin(), v.end());
	
	int med = n/2;
	bool flag = 1;
	
	for(i=0; i<n; i++){
		if(i < med){
			arr[v[i].Y] = v[med].X;
		} else{
			arr[v[i].Y] = v[med-1].X;
		}
			
	}
	
	for(i=1; i<=n; i++)
		cout << arr[i] << endl;
	 
	return 0;
}
