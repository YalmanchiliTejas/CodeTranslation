#include<bits/stdc++.h>
using namespace std;
int main(){
  while(1){
        int n,sum=0,ans=0,max=0,min=1001;
        cin >> n;
        if(n==0) break;
        int s[n];
        for(int i=0; i<n; i++){
          cin >> s[i];
          sum += s[i];
        }
        for(int i=0; i<n; i++){
          if(s[i] > max) max = s[i];
          if(s[i] < min) min =s[i];
        }
        sum = sum -max -min;
        ans = sum/(n-2);
        cout << ans << endl;
  }
  return 0;
}
