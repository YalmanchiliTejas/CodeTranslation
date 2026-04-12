#include <iostream>
#include <vector>
using namespace std;

int main(void){
  while(true){
    int n;
    cin >> n;
    if(n == 0)
      break;

    vector<int> p(n);
    int nmax = -1, nmin = 1001;
    int imax, imin;
    for(int i=0; i<n; i++){
      cin >> p[i];
      if(p[i] > nmax){
	nmax = p[i];
	imax = i;
      }
      if(p[i] < nmin){
	nmin = p[i];
	imin = i;
      }
    }

    int ave = 0;
    for(int i=0; i<n; i++){
      if(i != imax && i != imin)
	ave += p[i];
    }
    ave /= n-2;

    cout << ave << endl;
  }
  
  return 0;
}