
#include<bits/stdc++.h>
#include<math.h>
#include <stdio.h>
#include<vector>
#include<deque>
#include<stdlib.h>
//#include <algorithm>
#include<set>
#include <limits>
#include<string>
#define rep(i,n) for(int i = 0; i < n; i++)
typedef long long ll;
using namespace std;
#define llMAX numeric_limits<long long>::max()
#define intMAX numeric_limits<int>::max()
#define ll long long
#define d_5 100000
#define d9_7 1000000007

int main(void){
  ll n,k;
  cin >> n >> k;
  ll c=0;
  ll tmp;
  for(ll tk=k+1;tk<=n;tk++){
    if(n/tk>=1){
      c+=(n/tk)*(tk-k);
      //cout << (n/tk)*(tk-k) << endl;
    }
    if(n%tk==0)continue;
    if(k==0){
      tmp=0;
    }else{
      tmp=1;
    }
    c+=max((n%tk)-k+tmp,(ll)0);
    //cout << max((n%tk)-k+1,(ll)0) << endl;
  }
  cout << c;
	return 0;
}