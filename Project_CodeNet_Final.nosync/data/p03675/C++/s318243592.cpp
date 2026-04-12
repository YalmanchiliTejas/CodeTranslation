#include <bits/stdc++.h>

#define INF 100000000
#define MOD9(a) (a%1000000009)
#define MOD7(a) (a%1000000007)
#define ABS(a) (a<0?-(a):a)
#define MIN(a,b) (a>b?b:a)
#define MAX(a,b) (a>b?a:b)
#define REP(i,a) for(int i=0;i<a;i++) 

using namespace std;
int main(){
  vector<int> v;
  int n;
  cin >> n;

  REP(i, n){
    int po;
    cin >> po;
    if(i % 2 == 0){
      v.push_back(po);  
    }else{
      v.insert(v.begin(), po); 
    }
  }

  if(n % 2 == 0){
    REP(i, n){
      cout << v[i] << " ";
    }
  
  }else{
    REP(i, n){
      cout << v[n-1-i] << " ";
    }
  
  }
  cout << endl;

}

