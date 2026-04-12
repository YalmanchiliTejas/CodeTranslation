#include <iostream>
#include <string>
using namespace std;

int main() {
    int N;
    cin >>N;
    int h[60], ans=0, g=0;
    for(int i=0;i<N;i++) cin >> h[i];

    for(int i=0;i<N;i++) {
      if(h[i]>=g){
        ans += 1;
        g = h[i];
      }
    }
    cout << ans << endl;
}
