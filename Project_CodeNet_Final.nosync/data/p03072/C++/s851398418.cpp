#include<iostream>
#include<cmath>
#include<vector>
#include<map>
#include<string>
#include<algorithm>
using namespace std;
int main(){
  int N;
  cin >> N;
  int m=0;
  int c=0;
  for(int i=0; i<N; i++){
    int h;
    cin >> h;
    if(h>=m) c++;
    m = max(m, h);
  }
  cout << c << endl;
  return 0;
}