#include <iostream>
using namespace std;
int main(){
  int n,mx,mn;

  while( cin>>n && n ){
    int sum=0;
    mx = -1;
    mn = 10000;
    for( int i=0,j;i<n;i++ ){
      cin >> j;
      sum +=j;
      if( j>mx ) mx=j;
      if( j<mn ) mn =j;
    }

    sum = (sum - mx -mn)/(n-2);
    cout << sum << endl;
  }
  return 0;
}