#include <iostream>
#include <map>
#include <string>
#include <random>
#include <vector>
#include <algorithm>
#include <iomanip>
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define REP(i,N) FOR(i,0,N)
using namespace std;



int main(void){
  int n;
  int a;
  vector<int> iv;
  
  cin >> n;
  REP(i,n){
   cin >> a;
   iv.push_back(a);
  }
  
 
  vector<int> x(iv);
  sort(x.begin(),x.end());
  REP(i,n){
    if(iv[i] <x[n/2]){
     cout << x[n/2] << endl;
  }
    else{
      cout << x[n/2-1] << endl;
    }
    
  }
    
    
  
}