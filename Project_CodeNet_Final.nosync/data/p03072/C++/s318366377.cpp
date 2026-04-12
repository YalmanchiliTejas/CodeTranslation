#include "bits/stdc++.h"
using namespace std;

int main() {
    int N,H,max=0,count=0;
    cin >> N;
    for(int i=0;i<N;i++){
      cin >> H;
      if(H>=max){
        max=H;
        count++;
      }
    }
    cout << count << endl;
}
