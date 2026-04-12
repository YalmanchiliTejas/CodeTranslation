#include<iostream>
#include<cstdio>

using namespace std;

int main() {
  int n, high, low, sum, tmp;
  cin>>n;
  while(n>0) {
    high = 0;
    low = 1000;
    sum = 0;
    for(int i=0; i<n; i++) {
      cin>>tmp;
      sum += tmp;
      if(tmp<low)
	low = tmp;
      if(high<tmp)
	high = tmp;
    }
    sum -= (low+high);
    sum /= (n-2);
    cout<<sum<<endl;
    cin>>n;
  }
}