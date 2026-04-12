#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

int main(){
  
  long long int N;
  
  cin >> N;
  
   vector<long long> a(N);
  
  for(long long int i=0;i<N;i++){
    cin >> a[i];
  }
  
  multiset<long long> mlt;
  
  for(long long int i=0;i<N;i++){
    
    long long int j = a[i];
    
   auto k = mlt.lower_bound(j);
    
    if(k != mlt.begin()){ 
      k--;
      mlt.erase(k);
    }
    
    mlt.insert(j);
   
  }
  
  cout << mlt.size() << endl;
  
  return 0;
  
}
