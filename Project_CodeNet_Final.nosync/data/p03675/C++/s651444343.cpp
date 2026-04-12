#include <iostream>
#include <deque>

using namespace std;

int main(){
  int a[200000],n;
  deque<int> b;

  cin >> n;
  for(int i=0;i<n;i++){
    cin >> a[i];
  }

  if(n%2==0){
    for(int i=0;i<n;i++){
      (i%2==1)?b.push_front(a[i]):b.push_back(a[i]);
    }
  }else{
    for(int i=0;i<n;i++){
      (i%2==0)?b.push_front(a[i]):b.push_back(a[i]);
    }
  }

  for(int i=0;i<n;i++){
    cout << b.at(i) <<" ";
  }
  cout << endl;
}
