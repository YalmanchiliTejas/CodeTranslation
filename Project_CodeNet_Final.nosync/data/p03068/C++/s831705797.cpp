#include <algorithm>
#include<iostream>
#include<vector>
#include<map>
#include<set>
#include<string>

#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<limits.h>

using namespace std;
int main(){
  int k,n,ii;
  string s;
  char c;
  char* res;
  cin >> k >> s >> n;
  c = s [n-1];
  res = (char*)malloc(sizeof(char)*(k+1));
  memset(res,0,sizeof(char)*(k+1));

  for(ii=0;ii<k;ii++){
    if(c == s[ii]){
      res[ii] = s[ii];
    }
    else{
      res[ii] = '*';
    }
  }
  cout << res << endl;
  return 0;
}
