#include <cstdio>
#include <iostream>
#include <string>
#include <list>
#include <vector>
#include <queue>
#include <math.h>

using namespace std;

long long int gcd(long long int x, long long int y) {
	if (x < y){
      return gcd(y, x);
    }
	long long int r;
	while (r = x % y) {
		x = y;
		y = r;
	}
	return y;
}

int main(void){
  long long int n,i,j;
  cin >> n;
  long long int h[n];
  long long int maxH=0;
  int count = 0;
  for(i=0;i<n;i++){
    cin >> h[i];
    if(h[i]>=maxH){
      maxH=h[i];
      count++;
    }
  }
  cout << count << endl;
  return 0;
}


