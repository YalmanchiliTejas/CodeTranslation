#include <bits/stdc++.h>
using namespace std;
typedef long long int ll ;

#define pb     push_back
#define mp     make_pair
#define all(v) v.begin() , v.end()
#define allr(v) v.rbegin(), v.rend()
const ll INF =  0x3f3f3f3f;
const int MOD = 1e9+7;
const int MAX = 2e5+5;

int n, d;
vector<int> v(MAX);

int main(int argc, char const *argv[])
{
  // ios_base::sync_with_stdio(false);
  
  // #ifndef ONLINE_JUDGE
  // freopen("in","r",stdin);
  // freopen("out","w",stdout);
  // #endif

  scanf("%d" , &n);

  for(int i = 1 ; i <= n ; i++){
  	scanf("%d" , &d);
  	v[i] = d;
  }

  int indx;

  if(n%2 == 0){
  	indx = n;
  	while(indx > 1){
  		printf("%d " , v[indx]);
  		indx -= 2;
  	}
  	indx = 1;
  	while(indx < n){
  		printf("%d " , v[indx]);
  		indx += 2;
  	}
  }
  else{
  	indx = n;
  	while(indx >= 1){
  		printf("%d " , v[indx]);
  		indx -= 2;
  	}
  	indx = 2;
  	while(indx < n){
  		printf("%d " , v[indx]);
  		indx += 2;
  	}
  }

  return 0;
}  