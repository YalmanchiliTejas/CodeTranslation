#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> P;
typedef long long ll;
const int inf = numeric_limits<int>::max();

int main(void){
  int n;
  vector< int > a;
  cin >> n;
  a.resize(n);
  for(int i = 0;i < n;++i)cin >> a[i];
  for(int i = n-1;i >= 0;i -= 2){
    cout << a[i] << " ";
  }
  if(n % 2 == 0){
    for(int i = 0;i < n;i += 2){
      cout << a[i] << " ";
    }
  }else{
    for(int i = 1;i < n;i += 2){
      cout <<  a[i] << " ";
    }
  }
  cout << endl;
  return 0;
}
