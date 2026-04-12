#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <deque>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <bitset>
#include <algorithm>
#include <numeric>
#include <complex>
#include <functional>
#include <utility>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <climits>
#include <cctype>

using namespace std;

#define dump(n) cout<<"# "<<#n<<"="<<(n)<<endl
#define debug(n) cout<<__FILE__<<","<<__LINE__<<": # "<<#n<<"="<<(n)<<endl
#define repi(i,a,b) for(int i=int(a);i<int(b);i++)
#define rep(i,n) repi(i,0,n)
#define iter(c) __typeof((c).begin())
#define tr(c,i) for(iter(c) i=(c).begin();i!=(c).end();i++)
#define allof(c) (c).begin(),(c).end()
#define mp make_pair

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<string> vs;
typedef pair<int,int> pii;

int main()
{
	vector<pii> scores; // score,id
	for(int n,score;scanf("%d,%d",&n,&score),n|score;)
		scores.push_back(mp(score,n));
	
	sort(allof(scores),greater<pii>());
	
	vector<pii> places(1,mp(scores[0].second,1)); // id,place
	repi(i,1,scores.size()){
		if(scores[i].first<scores[i-1].first)
			places.push_back(mp(scores[i].second,places.back().second+1));
		else
			places.push_back(mp(scores[i].second,places.back().second));
	}
	
	sort(allof(places));
	
	for(int n;cin>>n;)
		cout<<places[n-1].second<<endl;
	
	return 0;
}