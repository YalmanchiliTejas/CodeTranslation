#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

int h,w;
string s[105];
vector<string> s1;
bool a[105];
bool b[105];
int main() {
  cin >> h >> w;
  for(int i = 0; i < h; i++) cin >> s[i];
  for(int i = 0; i < h; i++) {
    bool e = true;
    for(int j = 0; j < w; j++) {
      if(s[i][j] == '#') {
	e = false;
	break;
      }
    }
    if(e) a[i] = true;
  }
 
  for(int i = 0; i < w; i++) {
    bool e = true;
    for(int j = 0; j < h; j++) {
      if(s[j][i] == '#') {
	e = false;
	break;
      }
    }
    if(e) b[i] = true;
  }
 
  for(int i = 0; i < h; i++) {
    if(a[i])continue; 
    for(int j = 0; j < w; j++) {
      if(!b[j])
      cout << s[i][j];
    }
    cout << endl;
  }
}

  
  
