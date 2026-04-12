#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <list>
#include <stack>
using namespace std;

int main(){
  int n,k;string s;cin>>n>>s>>k;
  char tar=s[k-1];
  for(int i=0;i<n;++i)
	if(s[i]!=tar)s[i]='*';
  cout<<s<<endl;
  return 0;
}
