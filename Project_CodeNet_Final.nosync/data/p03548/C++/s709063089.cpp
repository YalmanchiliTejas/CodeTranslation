#include <iostream>
#include <cstring>
#include <map>
#include <iomanip>
#include <algorithm>
#include <cmath>
#include <set>
#include <vector>
#include <queue>
#include <list>
#include <numeric>

using namespace std;
typedef long long ll;

int main(){
  int x,y,z;
  cin>>x>>y>>z;
  int sum = 0;
  int count = 0;
  while(sum+y+z<=x-z){
    sum+=y+z;
    count++;
  }
  cout<<count<<endl;
  return 0;
}
