#include <iostream>
#include <vector>
#include<list>
#include <algorithm>
#include <string>
#include <math.h>
#include<map>
#include <utility>
#include <cstring>
#include <iomanip>
#include<queue>
#include<set>

using namespace std;
#define REP(i,k,n) for(int i=k;i<n;i++)
 
#define INF 1000000000
typedef long long  ll;

#define MOD 1000000007



int main()
{
    int N;
    cin >> N;
    ll a[N];
    multiset<ll> upset;
    REP(i,0,N){
      cin >> a[i];
    }
    
    REP(i,0,N){
      auto it = upset.lower_bound(a[i]);
      if(it==upset.begin()){
        upset.insert(a[i]);
      }else{
        --it;
        upset.erase(it);
        upset.insert(a[i]);
      }
    }
    cout << upset.size() << endl;
    return 0;
}
