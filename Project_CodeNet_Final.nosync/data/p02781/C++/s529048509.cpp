#include <iostream>
#include <vector>
#include <bitset>
#include <utility>
#include <string>
#include <queue>
#include <stack>
#include <algorithm>
#include <cmath>
#include <map>
#include <set>

using namespace std;
typedef long long ll;

ll ans=0;
int n;
string s;

ll combi(int n,int k){
  if(k==3) return 9*9*9*n*(n-1)*(n-2)/3/2/1;
  if(k==2) return 9*9*n*(n-1)/2/1;
  if(k==1) return 9*n/1;
  if(k==0) return 1;
}

int comb(int p,int k){
  if(k==0) return 1;
  if(p==n-1 && k==1) return s[p]-'0';
  if(p==n-1 && k>1) return 0;

  if(s[p]=='0'){
    return comb(p+1,k);
  }else if((s[p]-'0')>0){
    ll ans=0;
    ans+=combi(n-p-1,k);
    ans+=(s[p]-'1')*combi(n-p-1,k-1);
    ans+=comb(p+1,k-1);
    return ans;
  }
}
int main(){

  cin >> s;
  int K;
  cin >> K;
  n=s.size();

  cout << comb(0,K) << endl;

  return 0;
}