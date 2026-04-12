#include <bits/stdc++.h>
using namespace std;

int main(){
  int n,max;
  cin >> n ;
  cin >> max;
  int ans = 1;

  vector<int> h(n);

  for(int i = 0; i < n-1; i++)
  {
    int h;
    cin >> h;

    if(h>=max){
        ans++;
        max = h;
    }
  }
  cout << ans << endl;
  
}