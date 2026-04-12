#include <bits/stdc++.h> 
#define rep(i, n) for(int i = 1; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
typedef long long ll;
using namespace std;
int main(){
  int n;
  cin>>n;
  vector<int> h(n);
  cin>>h[0];
  rep(i,n){cin>>h[i];}
  int k=1;
  rep(i,n){vector<int> d(n);
    for(int j=0;j<=i;j++){
      d[j]=h[j];}
           sort(all(d));
           if(d[n-1]==h[i]){k++;}}
  cout<<k<<endl;
}