#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int n;
  cin>>n;
  queue<int> q;
  for(int i=0; i<n; i++){
    int tmp;
    cin>>tmp;
    q.push(tmp);
  }
  int max=0;
  int count=0;
  for(int i=0; i<n; i++){
    if(max<=q.front()){
      count++;
      max=q.front();
    }
    q.pop();
  }
  
  cout<<count<<endl;
}