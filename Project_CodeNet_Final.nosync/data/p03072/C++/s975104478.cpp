#include <bits/stdc++.h>
using namespace std;

int main() {
  int a;
  cin >> a; 
  vector<int> vec(a);
  int count=0;
  for(int i=0;i<a;i++){
    cin >> vec.at(i);
    //cout<<vec.at(i)<<endl;
    int n=0;
    while (vec.at(i-n)<=vec.at(i)){
      //cout<<i-n<<endl;
      n++;
      if(i-n==-1){
      count++;
      break;
      }
    }
  }
  cout<<count<<endl;
  
  
}