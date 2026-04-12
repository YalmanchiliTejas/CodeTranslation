#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
  int t[101],n,s;
  vector<int> r;
  while(1){
    scanf("%d,%d",&n,&s);
    if(n==0&&s==0) break;
    t[n]=s;
    r.push_back(s);
  }
  sort(r.begin(),r.end());
  r.erase(unique(r.begin(),r.end()),r.end());
  while(scanf("%d",&n)>0){
    printf("%d\n",r.end()-find(r.begin(),r.end(),t[n]));
  }
  return 0;
}