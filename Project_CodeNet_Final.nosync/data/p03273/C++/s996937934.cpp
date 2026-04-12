#include<iostream>
#include<vector>
using namespace std;

int main()
{
  int h, w;
  cin >> h >> w;

  char a[100][100];

  vector<int> flagR(w, 0);
  vector<int> flagC(h, 0);

  for(int i = 0; i < h; i++){
    for(int j = 0; j < w; j++){
      cin >> a[i][j];;

      if(a[i][j] == '.'){
        flagR[j]++;
        flagC[i]++;
      }
    }
  }

  for(int i = 0; i < h; i++){
    for(int j = 0; j < w; j++){
      if(flagR[j] != h && flagC[i] != w) cout << a[i][j];
    }

    if(flagC[i] != w) cout << endl;

  }

  return 0;

}
