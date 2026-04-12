#include <bits/stdc++.h>
#define r(i,n) for(int i = 0; i<n; i++)
using namespace std;

int main(){
  int n,count=0;
  cin >> n;
  vector<int> v(n);
  r(i,n){
    cin >> v.at(i);
    if(*max_element(v.begin(),v.begin()+i)<=v.at(i))count++;
  }
  cout << count << endl;
}