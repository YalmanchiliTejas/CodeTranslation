#include <iostream>
#include <cstring>
#include <string>
#include <set>
#include <map>
#include <vector>
#include <queue>
#include <algorithm>
#include <bitset>
#include <cstdlib>
#include <cmath>
#define INF 1000000000
#define MOD 1000000007
#define ll long long int
using namespace std;


int main(){
 int N; cin>>N;
 vector <int> h; h.resize(N+1,0);
 for(int i=1;i<=N;i++) cin>>h[i];
 int ans = 1;
 for(int i=2;i<=N;i++){
   for(int j=1;j<i;j++){
     if(h[j] <= h[i]){
       if(j==i-1) ans++;
     }
     else break;

   }
 }

cout<<ans<<endl;
  return 0;
}