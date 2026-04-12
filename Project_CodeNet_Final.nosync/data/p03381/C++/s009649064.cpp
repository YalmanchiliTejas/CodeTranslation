#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>
#include <climits>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> pii;

#define INF INT_MAX/3
#define REP(i,n) for(int i=0;i<n;i++)

int main(){
	
	int N;
	vector<pair<ll,ll>> ar;
	vector<ll> br;		
	cin>>N;
	REP(i,N){
		ll a;
		cin>>a;
		ar.emplace_back(a,i);
		br.push_back(a);
	}
	
	sort(ar.begin(),ar.end());
	
	ll poll = N/2 - 1;
	for(ll i = 0; i < N; i++ ){
		
		auto pos = br[i];

			if(pos <= ar[poll].first){
				cout<<ar[poll+1].first<<endl;
			}
			else{
				cout<<ar[poll].first<<endl;
			}
	}

	return 0;
}

