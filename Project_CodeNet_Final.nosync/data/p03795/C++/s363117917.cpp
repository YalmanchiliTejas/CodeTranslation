#include <iostream>
#include <limits.h>
#include <queue>
#include <algorithm>
#include <map>
#include <cstring>
#include <utility>
#include <vector>
#include <cmath>

using namespace std;

typedef pair<int,int> P;
typedef long long int ll;


int main(){

  ios_base::sync_with_stdio(false);

  int N = 0;
  cin>>N;

  int a = floor(N/15);
  int ret = N*800-a*200;
  cout<<ret<<endl;
  
  return 0;
}
