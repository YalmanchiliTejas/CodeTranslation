#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define fbo find_by_order
#define ook order_of_key
#define INF 1e9

typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<int> vi;
typedef vector < pair<int, int> > vii;
typedef long double ld;
typedef tree<pair<int,int>, null_type, less<pair<int,int> >, rb_tree_tag, tree_order_statistics_node_update> pbds;
typedef set<int>::iterator sit;
typedef map<int,int>::iterator mit;
typedef vector<int>::iterator vit;


ll h, w, cnt;
string s;

int main()
{
	cin >> h >> w;
	for(int i = 0; i < h; i++){
		cin >> s;
		for(int j = 0; j < w; j++){
			if(s[j]=='#'){
				cnt++;
			}
		}
	}
	if(cnt==h+w-1){
		cout << "Possible";
	}
	else{
		cout << "Impossible";
	}
	return 0;
}
