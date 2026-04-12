#include<bits/stdc++.h>

using namespace std;
typedef pair<int, int> P;
typedef long long int ll;

int main(){
  int n;cin>>n;
  vector<int> x(n), y(n);
  for(int i=0;i<n;i++){
    int a;cin>>a;
    x[i]=y[i]=a;
  }
  sort(y.begin(), y.end());
  for(int i=0;i<n;i++){
    if(x[i]<=y[n/2-1])cout<<y[n/2]<<endl;
    else cout<<y[n/2-1]<<endl;
  }
}
