#include <bits/stdc++.h>

using namespace std;

int main(void)
{

  while(1){
    int n; cin >> n;

    vector<int> array(n, 0);
    if(n == 0) break;

    int sum = 0;
    for(int i = 0; i < n; i++){
      int input; cin >> input;
      array[i] = input;
    }
   
    sort(array.begin(), array.end() );

   
    for(int i = 1; i < n-1; i++){
      sum += array[i];
    }
    cout << sum/(n - 2)<< endl;
  }
  return 0;
}