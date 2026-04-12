
#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define sc(x) scanf("%lld",&x)
#define pr(x) printf("%lld\n",x)
#define clr(x) memset(x, 0, sizeof(x))
#define all(x) x.begin(), x.end()
typedef pair<ll, ll> pii;
typedef vector< ll > vl;
typedef vector< pii > vpii;

//DONT WASTE YOUR TIME
//prove yourself
//remember....fuck ps&&as hard....show them your are better then them
//Be confident.....dont lose hope.......You can do it.....
//dimaag  khoob h tere meh ....bas concentration ki kami h
//CONCENTRATE
//A,B,C dimaag nhi ...observation h .....zyaada mat sochna unme.....bas observe karna dhyaan se aur implement kar daal jitni jaldi ho sake

//capture it

const ll N= 1e6+55,mod = 1e9+7;

int main() {
 	//freopen("task.in","r",stdin);freopen("task.out","w",stdout);
	string s;
	cin>>s;
	ll i,j;
	for(i=1;i<s.size();i++){
		if(s[i]=='C' && s[i-1]=='A'){
			cout<<"Yes\n";
			return 0;
		}
	}
	cout<<"No\n";
}