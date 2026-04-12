#include<bits/stdc++.h>
using namespace std;

int main(){
  int n;
  cin >> n;
  multiset<int> ms;
  for(int i = 0;i < n;i++){
    int a;
    cin >> a;
    auto it = ms.lower_bound(a);
    if(it == begin(ms)){
      ms.insert(a);
    }
    else{
      it = prev(it);
      ms.erase(it);
      ms.insert(a);
    }
  }
  cout << ms.size() << endl;
}