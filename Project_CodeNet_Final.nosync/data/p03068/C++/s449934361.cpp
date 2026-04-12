#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <math.h>
#include <string.h>
#include <map>
#include <numeric>
using namespace std;

const int MOD = 1000000007;
typedef long long ll;


int main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);
  int n,k;
  string s;
  cin>>n>>s>>k;
  for(int i=0;i<n;i++){
    if(s[k-1]==s[i]){
      cout<<s[i];
    }else{
      cout<<"*";
    }
  }
  cout<<endl;
}
