#include <iostream>
#include <algorithm>

using namespace std;

int main(){
  int n,s[1000];

  while(cin >> n){
    int sum;
    if(!(n)) break;
    sum = 0;
    for(int i = 0;i<n;i++) cin >> s[i],sum += s[i];
    sort(s,s+n);
    printf("%d\n",(sum - s[0] - s[n-1]) / (n-2));
  }

  return 0;
}