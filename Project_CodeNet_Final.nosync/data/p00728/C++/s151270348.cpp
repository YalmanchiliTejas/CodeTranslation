#include <bits/stdc++.h>
using namespace std;

#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))

typedef long long LL;

int main(){
  int n;
  while(1){
    cin >> n;
    if(n==0) return 0;
    vector<int> s(n);
    for(int i=0;i<n;i++){
      cin >> s[i];
    }
    sort(s.begin(),s.end());
    int ans=0;
    for(int i=1;i<n-1;i++){
      ans+=s[i];
    }
    cout << ans/(n-2) << endl;
  }
  return 0;
}

