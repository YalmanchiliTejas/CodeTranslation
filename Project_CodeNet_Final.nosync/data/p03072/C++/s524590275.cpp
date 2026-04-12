#include <bits/stdc++.h>
using namespace std;
#define pp pair<int,int>
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
#define rep2(i,m,n) for(int (i)=(m);(i)<(n);(i)++)
#define ll long long
#define ld long double
#define all(a) (a).begin(),(a).end()

int main(){
  int n;
  cin>>n;
  vector<int> h(n);
  rep(i,n) cin>>h[i];
  reverse(all(h));
  int count=0;
  rep(i,n-1){
    rep2(j,i+1,n){
  if(h[i]<h[j]){
    count++;
    break;
  }
    }
  }
    cout<<n-count<<endl;
  return 0;
    }