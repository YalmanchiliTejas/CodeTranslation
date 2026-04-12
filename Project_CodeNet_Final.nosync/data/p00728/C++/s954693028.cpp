#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void){
  while(true){
    int n;
    cin >> n;
    if(n == 0){ break; }

    vector<int> input(n);
    for(int i = 0; i < n; i++){ cin >> input[i]; }
    sort(input.begin(), input.end());
    
    int ans = 0;
    for(int i = 1; i < n - 1; i++){ ans += input[i]; }
    ans /= (n - 2);
    cout << ans << endl;
  }


  return 0;
}