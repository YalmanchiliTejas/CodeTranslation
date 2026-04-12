#include <cstdio>
#include <cstring>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <stack>
#include <queue>
#include <vector>
#include <set>
using namespace std;

#define rep(i,n) for(int i=0;i<(n);i++)
#define mp(a,b) make_pair(a,b)
#define pb(a) push_back(a)
#define dbg(x) cout<<#x"="<<x<<endl

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<pii, int> ppi;

#define INF 1000000000

#define T true
#define F false
// T:left, F:right
//             a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p,q,r,s,t,u,v,w,x,y,z
bool keys[] = {T,T,T,T,T,T,T,F,F,F,F,F,F,F,F,F,T,T,T,T,F,T,T,T,F,T};

int main(){
  bool last;
  bool first=true;
  int res=0;
  while(true){
    char c;
    scanf("%c", &c);
    
    if(c=='#'){
      break;
    } else if(first){
      res=0;
      first=false;
      last=keys[c-'a'];
    } else if(c=='\n'){
      cout << res << endl;
      first=true;
      res=0;
    } else{
      if(keys[c-'a']!=last){
	last = !last;
	res++;
      }
    }
  }


}