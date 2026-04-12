#include <iostream>
#include <algorithm>

using namespace std;

int main(){
  int n,m;
  while(true){
    cin >>n >>m;
    if (!n&&!m)
      break;
    int t[n+m+1];
    for(int i=0;i<n;i++)
      cin >> t[i];
    for(int i=n;i<n+m;i++)
      cin >> t[i];
    t[n+m] = 0;
    sort(t,t+n+m+1);
    int max = 0;
    for(int i=0;i<n+m;i++)
      if (max<(t[i+1]-t[i]))
	max = t[i+1]-t[i];
    cout <<max << endl;
  }
  return 0;
}