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
	      	  
	      	  string s;
	      	  cin >> s;
	      	  int n=s.size();
	      	  
	      	  for(i=0;i<=n-2;i++){
	      		  if(s[i]=='A' && s[i+1]=='C'){
	      			  cout << "Yes" << endl;
	      			  return 0;
	      		  }
	      	  }
	      	  
	      	  cout << "No" << endl;

	          return 0;
}
