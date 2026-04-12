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

int a[200010],b[200010];

int main(void){
	          int i;

	          int n,m;
	          cin >> n;
	          for(i=1;i<=n;i++) cin >> a[i];

	          m=n;
	          if(n%2==0){
	        	  for(i=1;i<=n/2;i++){
	        		  b[i]=a[m];
	        		  m--;
	        		  b[n-i+1]=a[m];
	        		  m--;
	        	  }
	          }else{
	        	  for(i=1;i<=n/2;i++){
	        		  b[i]=a[m];
	        		  m--;
	        		  b[n-i+1]=a[m];
	        		  m--;
	        	  }
	        	  b[(n+1)/2]=a[m];
	          }

	          for(i=1;i<n;i++){
	        	  cout << b[i] << ' ';
	          }

	          cout << b[n] << endl;


	          return 0;
}
