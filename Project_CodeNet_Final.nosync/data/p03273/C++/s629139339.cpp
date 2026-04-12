#include <iostream>
#include <vector>
using namespace std;

int main() {
	int H, W;
  cin >> H >> W;
  vector<vector<char> > a;
  vector<char> z;
  for (int i = 0; i<W; i++) {
    z.push_back('?');
  }
  
  for (int i = 0; i<H; i++) {
    int count=0;
    vector<char> b;

 	for (int j = 0; j<W; j++) {      
      char ness;cin >> ness;b.push_back(ness);
      if (b[j] == '.'){
        count++;
      }
    }
	if (count != W) {    
    	a.push_back(b);
    }
    else {
    	a.push_back(z);
    }
   
  }
  
  for (int i = 0; i<W; i++) {
    int count_i = 0;
    for (int j = 0; j<H; j++) { 
      if (a[j][i] == '.' || a[j][i] == '?'){
        count_i++;
      }
    }
    if (count_i == H)  {
      for (int j = 0; j<H; j++) { 
        a[j][i] = '?';
      }
    }
  }
  
  for (int i = 0; i<H; i++) {
    int cnt=0;
    for (int j = 0; j<W; j++) {   
      if (a[i][j] != '?') {
      	cout << a[i][j];
      }else{cnt++;}
    }    
    if(cnt!=W)cout << endl;

  }      
}

