#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <bitset>
#include <map>
#include <tuple>
#include <unordered_map>
#include <list>
#include <numeric>
#include <utility>
#include <iterator>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <climits>
#include <ctime>
#include <cassert>

#define INF 1000000000
#define LINF 9000000000000000000
#define mod 1000000007

#define rep(i,n) for(int i=0;i<int(n);i++)
#define rrep(i,n) for(int i=n-1;i>=0;i--)
#define REP(i,a,b) for(int i=(a);i<int(b);i++)
#define all(x) (x).begin(),x.end()
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<long long>vll;
typedef pair<int,int> pi;
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};
int ddx[8]={-1,-1,0,1,1,1,0,-1};
int ddy[8]={0,1,1,1,0,-1,-1,-1};
bool debug=false;

/*---------------------------------------------------*/

int main(){
  int n,l,r;
  while(cin>>n>>l>>r,n|l|r){
    vector<int> data(n);
    for(int i=0;i<n;i++){
      cin>>data[i];
    }

    int ans=0;
    for(int i=l;i<=r;i++){
      int index=-1;
      for(int j=0;j<n;j++){
	if(i%data[j]==0){
	  index=j+1;break;
	}
      }

      if(index!=-1){
	if(index%2==1)ans++;
      }else{
	if(n%2==0)ans++;
      }
    }
    
    cout<<ans<<endl;
  }
  return 0;
}

