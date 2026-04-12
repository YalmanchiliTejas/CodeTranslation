#include<iostream>
#include<sstream>
#include<fstream>
#include<string>
#include<vector>
#include<deque>
#include<queue>
#include<stack>
#include<set>
#include<map>
#include<algorithm>
#include<functional>
#include<utility>
#include<bitset>
#include<cmath>
#include<cstdlib>
#include<ctime>
#include<cstdio>

using namespace std;

#define REP(i,n) for(int i=0;i<int(n);i++)
#define foreach(c,itr) for(__typeof((c).begin()) itr=(c).begin();itr!=(c).end();itr++)
typedef long long ll;
typedef pair<int,int> P;

int main(void){
	          int i;

	      	  cin.tie(0);  ios_base::sync_with_stdio(false);

	      	  int N;
	      	  cin >> N;
	      	  vector<P> v;
	      	  for(i=0;i<N;i++){
	      		  int x;
	      		  cin >> x;
	      		  v.push_back(P(x,i));
	      	  }

	      	  sort(v.begin(),v.end());

	      	  vector<P> u;
	      	  for(i=0;i<=(N-1)/2;i++){
	      		  u.push_back(P(v[i].second,v[(N+1)/2].first));
	      	  }

	      	  for(i=(N+1)/2;i<N;i++){
	      		  u.push_back(P(v[i].second,v[(N-1)/2].first));
	      	  }

	      	  sort(u.begin(),u.end());

	      	  for(i=0;i<N;i++){
	      		  cout << u[i].second << endl;
	      	  }

	          return 0;
}
