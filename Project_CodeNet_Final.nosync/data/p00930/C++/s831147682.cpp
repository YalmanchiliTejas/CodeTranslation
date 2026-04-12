#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>

#include <complex>

#include <functional>
#include <cassert>

typedef long long ll;
using namespace std;

#define debug(x) cerr << #x << " = " << (x) << endl;


#define mod 1000000007 //1e9+7(prime number)
#define INF 1000000000 //1e9
#define LLINF 2000000000000000000LL //2e18
#define SIZE 300010

/* Starry Sky Tree */
//0-index

struct StarrySkyTree{
  typedef int Type;
  int segn2;
  vector<Type> data,s_data;
  
  StarrySkyTree(int n){
    for(segn2=1;segn2<n;segn2*=2);
    data.assign(segn2*2,0);
    s_data.assign(segn2*2,0);
  }
  
  //get minimum value of [a,b]
  Type query(int a,int b,int l=0,int r=-1,int k=0){
    if(r==-1) r+=segn2;
    if(r<a || b<l) return INF;
    if(a<=l && r<=b) return data[k] + s_data[k];
    return min(query(a,b,l,(l+r)/2,k*2+1),query(a,b,(l+r)/2+1,r,k*2+2))+s_data[k];
  }
  
  //add x to [a,b]
  Type add(int a,int b,Type x,int l=0,int r=-1,int k=0){
    if(r==-1) r+=segn2;
    if(a<=l && r<=b){
      s_data[k]+=x;
    }else if(a<=r && l<=b){
      data[k] = min(add(a,b,x,l,(l+r)/2,k*2+1),add(a,b,x,(l+r)/2+1,r,k*2+2));
    }
    return data[k] + s_data[k];
  }
  
};



int main(){
  int n,q;
  char s[SIZE];
  int sum[SIZE];
  priority_queue<int> right;
  scanf("%d%d%s",&n,&q,s);

  StarrySkyTree seg(n);
  
  for(int i=0;i<n;i++){
    if(s[i] == '('){
      sum[i] = 1;
    }else{
      sum[i] = -1;
      right.push(-i);
    }

    if(i > 0){
      sum[i] += sum[i-1];
    }

    seg.add(i,i,sum[i]);
  }
  
  for(int i=0;i<q;i++){
    int p, ans;
    scanf("%d",&p);
    p--;
    
    if(s[p] == '('){
      s[p] = ')';
      right.push(-p);
      seg.add(p,n-1,-2);

      while(right.size() && s[-right.top()] == '(') right.pop();

      ans = -right.top();
      s[ans] = '(';
      seg.add(ans,n-1,2);
      
    }else{
      s[p] = '(';
      seg.add(p,n-1,2);

      int l=0, r=p;

      while(l<r){
        int mid = (l+r)/2;
        if(seg.query(mid,n-1) >= 2){
          r = mid;
        }else{
          l = mid+1;
        }
      }

      ans = l;
      s[ans] = ')';
      right.push(-ans);
      seg.add(ans,n-1,-2);
    }

    printf("%d\n",ans+1);
  }
  
  return 0;
}