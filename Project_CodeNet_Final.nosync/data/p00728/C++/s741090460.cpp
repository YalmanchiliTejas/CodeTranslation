#include<iostream>
#include<algorithm>
#include<set>
#include<map>
#include<vector>
#include<queue>
#include<deque>
#include<string>
#include<cstring>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include <climits>

using namespace std;

#define REP(i,a,n) for(int i = a ; i < n ; i++)
#define rep(i,n) REP(i,0,n)

typedef long long ll;

void solve(){
}

int main(){
  int n;

  while(cin>>n,n){
    int sum = 0;
    int max = INT_MIN;
    int min = INT_MAX;

    rep(i,n){
      int s;
      cin>>s;
      sum += s;

      if(max < s) max = s;
      if(min > s) min = s;
    }

    cout<<(sum - max - min) / (n-2)<<endl;
  }
}