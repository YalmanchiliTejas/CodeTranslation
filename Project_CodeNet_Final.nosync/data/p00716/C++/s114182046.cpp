#include <iostream>

using namespace std;

int main(void){
  int m;

  cin >> m;
  for(int i=0; i<m; i++){
    int a, b, n, max = 0;

    cin >> a >> b >> n;
    for(int j=0; j<n; j++){
      int c, e; double d;

      cin >> c >> d >> e;
      if(c == 0){
        int A = a, B = 0;
        for(int k=0; k<b; k++){
          B = B + (int)(A * d);
          A = A - e;
        }

        if(max < A + B)
          max = A + B;
      } else {
        int A = a;
        for(int k=0; k<b; k++){
          A += (int)(A * d) - e;
        }

        if(max < A)
          max = A;
      }
    }

    cout << max << endl;
  }

  return 0;
}