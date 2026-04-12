#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <list>
#include <stdio.h>
#include <stdlib.h>
#include <cmath>

using namespace std;

long long count(int n, long long x){
    long long p = pow(2,n)-1;
    long long all = pow(2,n+1)-3;
    long long ans = 0;
    if(n == 0 && x==1){
        return 1;
    }
    else if(x==0 || x==1){
        return 0;
    }
    else if(all+1 >= x){
        ans+=count(n-1,x-1);
    }
    else if(all+2 == x){
        ans += p+1;
    }
    else if(2*all+1 >= x){
        ans +=p+1;
        ans+=count(n-1,x-all-2);
    }
    else if(2*all+2 <= x){
        ans += 2*p+1;
    }
    return ans;
}

int main(){
  int n;
  long long x;
  string bager("P");
  cin >> n >> x;
  
//   for(int i = 0; i < n; i++){
//       bager += bager;
//       bager.insert(bager.length()/2,"P");
//       bager.insert(0, "B");
//       bager.push_back('B');
//      // cout << bager << endl;
//   }
  
//   for(int i =0; i < x; i++){
//       if(bager[i] == 'P')
//         cnt++;
//   }
  if(n ==0)
    cout << 1<<endl;
  else
    cout << count(n,x)<< endl;
  return 0;
}
