#include<iostream>
#include<algorithm>
#include<math.h>
#include<cmath>
#include<vector>
#include<stack>
#include<queue>
#include<functional>
#include<map>
#include<set>
#include <string>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
map<string, int> mp;
#define ll long long

int main() {
    int n;
    cin >> n;
    int a[100];
    int c = 0;
    rep(i, n) {
        int b;
        cin >>b;
        c += b;
      if(i==0)a[i]=b;
      else a[i]=a[i-1]+b;
    }
    int jg = c / n;
    int k = 1000;
    rep(i, n) {
        int kk = 0;
        if ((a[i] - (i + 1)*jg) < 0) {
            kk = a[i] / (i + 1);
            if (k > kk)k = kk;
        }
      
 }
  
  if(k==1000)cout<<jg<<endl;
  else  cout << k << endl;
    return 0;
}
