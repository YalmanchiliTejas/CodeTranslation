#include<iostream>
using namespace std;
int main()
{
  while(true){
    int maxamnt = 0;
    char ans;
    for(int i = 0; i < 5; ++i){
      int bn,an;
      cin >> bn;
      cin >> an;
      if( an + bn == 0 ) return 0;
      if( maxamnt < an+bn ){
	maxamnt = an+bn;
	ans = 'A' + i;
      }
    }
    cout << ans << ' ' << maxamnt << endl;
  }
  return 0;
}