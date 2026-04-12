#include <iostream>
using namespace std;

int main() {
	int h, w, tate, yoko, m;
	char a[105][105];
	cin >> h >> w;
	
	for (int i = 0; i < h; i++) {
	    cin >> a[i];
	}
	
	for (int i = 0; i < h; i++) {
	    for (int j = 0; j < w; j++) {
          
          	if (m == 0) {
	        	for (int k = 0; k < w; k++) {
	            	if (a[i][k] == '.') yoko++;
            	}
            }
          	
	        for (int l = 0; l < h; l++) {
	            if (a[l][j] == '.') tate++; 
	        }
          	
          	if (yoko != w && tate != h) cout << a[i][j];
          	if (yoko != w && j == w - 1) cout << endl;
          	m++;
        	tate = 0;
	    }
      	m = 0;
      	yoko = 0;
	}
	return 0;
}
