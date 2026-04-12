#include<bits/stdc++.h>

using namespace std;

int main(){
int N; cin>> N;
  vector<int> A(N); for(int i = 0; i < N; i++){ cin >> A[i];}
  
  multiset<int> mp;
  
  for(int i = 0; i  <N; i ++){
   auto c = mp.lower_bound( A[i]);
    if( c != mp.begin()){  c--; mp.erase(c);}
                 mp.insert( A[i]);}
                          
                          
                      cout << mp.size() << endl; return 0;}
    
    