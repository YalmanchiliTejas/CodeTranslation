#include<bits/stdc++.h>
using namespace std;
int main(){
  int N;
  cin >> N;
  vector<int>m(N);
  for(int i = 0;i < N;i++){
    cin >> m.at(i);
  }
  int cou = 1;
  int x = m.at(0);
  for(int i = 1;i < N;i++){
    if(m.at(i) >= x){
    cou++;
    x = m.at(i);
  }
}
cout << cou <<endl;    
    
  }
    