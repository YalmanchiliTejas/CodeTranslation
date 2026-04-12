#include<bits/stdc++.h>
using namespace std;

bool max_check(vector<int> v, int i){
  int a=v[i];
  sort(v.begin(), v.begin()+i);
  if (v[i-1]<=a) return true;
  else return false;
}

int main(){
  int N;
  cin >> N;
  if(N==1){
    cout << 1 <<endl;
    return 0;
  }
  vector<int> v(N);
  for(int i=0; i<N; i++) cin >> v[i];
  
  int ans=1;
  for(int i=1; i<N; i++){
    bool x=max_check(v, i);
    if(x) ans++;
  }
  cout << ans<<endl;
}