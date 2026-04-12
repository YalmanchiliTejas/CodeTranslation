#include<iostream>
using namespace std;

int main()
{
  int n;
  cin >> n;

  int maxH = 0;
  int cnt;

  for(int i = 0; i < n; i++){
    int h;
    cin >> h;

    if(i == 0 || h >= maxH){
      cnt++;
      maxH = h;
    }
  }

  cout << cnt << endl;

  return 0;

}
