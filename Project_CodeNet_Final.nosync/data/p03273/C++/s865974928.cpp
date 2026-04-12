#include<bits/stdc++.h>
#define ll long long int
using namespace std;

int main(void) {
  int h,w;
  cin >> h >> w;

  char a[1024][1024];
  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      cin >> a[i][j];
    }
  }

  vector<int> ii,jj;
  for (int i = 0; i < h; i++) {
    bool c = true;
    for (int j = 0; j < w; j++) {
      if(a[i][j]=='#'){
	c=false;
	break;
      }
    }
    if(c){
      ii.push_back(i);
    }
  }

  for (int j = 0; j < w; j++) {
    bool c = true;
    for (int i = 0; i < h; i++) {
      if(a[i][j]=='#'){
	c=false;
	break;
      }
    }
    if(c){
      jj.push_back(j);
    }
  }

  for (int i = 0; i < h; i++) {
    if(find(ii.begin(), ii.end(), i) != ii.end()){
      continue;
    }
    for (int j = 0; j < w; j++) {
      if(find(jj.begin(), jj.end(), j) == jj.end()){
	cout << a[i][j];
      }
    }
    cout << endl;
  }

  return 0;
}
