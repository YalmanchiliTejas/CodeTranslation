#include <iostream>
using namespace std;

int main()
{
  int n, ans=1, no=0;
  int h[20];
  cin >> n;
  for(int i=0;i<n;i++){
    cin >> h[i];
  }
  
  for(int i=1;i<n;i++){
    for(int j=0;j<i;j++){
      if(h[j]>h[i])	no=1;
    }
    if(no==0)	ans++;
    no=0;
  }
  cout << ans <<endl;
}