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

#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<limits.h>

using namespace std;



int main(){
  long ii,jj,kk,n,q;
  int k;
  vector<int> a;

  cin >> n;

  a.resize(n);

  for(ii=0;ii<n;ii++){
    cin >> a[ii];
  }

  cin >> q;
  int ret;

  for(ii=0;ii<q;ii++){
    cin >> k;
    //ret = lower_bound(&a,k);
    auto it = lower_bound(a.begin(),a.end(),k);
    if(it == a.end()){
      cout << a.size() << endl;
    }
    else{
      cout << distance(a.begin(),it) << endl;
    }

  }
  
  //for(ii=0;ii<q;ii++){
  //  cin >> k;
  //  if(binSearch(&a,k)){
  //    cout << "1" << endl;
  //  }
  //  else{
  //    cout << "0" << endl;
  //  }
  //}
  
  return 0;
}

