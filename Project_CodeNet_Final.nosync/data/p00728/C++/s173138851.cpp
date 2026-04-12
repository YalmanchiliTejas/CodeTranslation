#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
  int n, a[101], t;

  while(cin>>n && n){
    for(int i = 0; i < n; i++){
      cin >> a[i];
    }
    sort(a, a+n);
    t = 0;
    for(int i = 1; i < n-1; i++){
      t += a[i];
    }

    cout << (t/(n-2)) << endl;
  }

  return 0;
}