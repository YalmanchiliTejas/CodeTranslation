#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <math.h>
#include <stdlib.h>
#include <map>
#define rep(i,n) for(int i=0; i < (n); i++)
#define INF 1001001
using namespace std;

int main(){
  int n;
  cin >> n;
  long long a[n];
  long long tmp=0;
  rep(i,n) cin >> a[i];
  long long result=0;
  for(int i=1;i<n;i++){
    tmp = (tmp+a[i-1])%1000000007;
    result = (result+a[i]*tmp)%1000000007;
  }

  cout << result << endl;
    
}