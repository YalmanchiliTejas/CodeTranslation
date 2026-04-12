#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  deque<int> a;
  for(int i=0;i<N;i++){
    if(i%2==0){
      int x;
      cin >> x;
      a.push_back(x+1);
    }
    else{
      int x;
      cin >> x;
      a.push_front(x+1);
    }
  }
  if(N%2==1)reverse(a.begin(),a.end());
  for(int i=0;i<a.size();i++){
    if(a[i]!=0)cout << a[i]-1 << ' ';
  }
}
