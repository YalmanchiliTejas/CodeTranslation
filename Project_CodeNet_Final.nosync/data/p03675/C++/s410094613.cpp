#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<cstdio>
#include<stack>
#include<cstring>
#include<string.h>
#include<cmath>
using namespace std;
typedef long long ll;

int main(){
  int n;
  stack<int>s;
  queue<int>q;

  scanf("%d",&n);
  for(int i=0;i<n;i++){
    int a;
    scanf("%d",&a);
    if((n+i)%2==0) q.push(a);
    else s.push(a);
  }

  while(!s.empty()){
    printf("%d ",s.top());
    s.pop();
  }
  while(!q.empty()){
    printf("%d",q.front());
    q.pop();
    if(q.empty()) printf("\n");
    else printf(" ");
  }
  
  return 0;
}
