#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main(void){
    int n;
    vector<int> h;
    
    cin >> n;

    for(int i = 0; i < n; i++){
      int a;
      cin >> a;
      h.push_back(a);
    }

    int max = 0;
    int ans = 0;
    for(int i = 0; i < n; i++){
      if(h[i] >= max){
        max = h[i];
        ans++;
      }
    }

    cout << ans << endl;

    return 0;
}