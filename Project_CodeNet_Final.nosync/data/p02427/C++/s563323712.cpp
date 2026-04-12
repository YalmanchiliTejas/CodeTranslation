#include <algorithm>
#include<iostream>
#include<vector>
#include<deque>
#include<queue>
#include<list>
#include<stack>
#include<map>
#include<set>
#include<string>
#include <sstream>
#include<bitset>

#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<limits.h>

using namespace std;


int main(){
  long ii,jj,kk,n;
  vector<int> a;
  bitset<32> m;

  cin >> n;

  for(ii=0;ii<pow(2,n);ii++){
    m = ii;
    cout << ii << ":";

    for(jj=0;jj<n;jj++){
      if(m.test(jj)){
        cout << " " << jj;
      }
    }
    
    cout << endl;
  }

  
  return 0;
}

