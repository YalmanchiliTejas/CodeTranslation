#include <bits/stdc++.h>

using namespace std;

int n;
int main(){

cin.tie(0);
ios::sync_with_stdio(false);

cin>>n;

deque<int> dq;

for(int i=1; i<=n; i++){
  int c;
  cin>>c;
  if(i%2) dq.push_front(c);
  else dq.push_back(c);
}

if(n%2){
  for(int i=0; i<n; i++){
    cout<<dq[i]<<" ";
  }
  cout<<endl;
}
else{
  for(int i=n-1; i>=0; i--){
    cout<<dq[i]<<" ";
  }
  cout<<endl;
}


}
