#include<iostream>
#include <string>
using namespace std;

int main() {
    int H;
    int W;
    cin >> H;
    cin >> W;
	bool a[H][W];
	for (int i = 0; i < H; i++) {
	    string s;
	    cin >> s;
	    for (int j = 0; j < W; j++) {
	        if (s[j] == '.') {
	            a[i][j] = false;
	        } else {
	            a[i][j] = true;
	        }
	    }
	}

	int gyou = 0;
	bool b[H][W];
	for (int i = 0; i < H; i++) {
	    bool aho = false;
	    for (int j = 0; j < W; j++) {
	        //一個でもa[i][j]が#がある
	        if (a[i][j]) {
	            aho = true;
	        }
	    }
	    //#がある場合
	    if (aho) {
	        for (int j = 0; j < W; j++) {
	            b[gyou][j] = a[i][j];
	        }
	        gyou++;
	    }
	}

	int retsu = 0;
	bool c[gyou][W];
	for (int j = 0; j < W; j++) {
	     bool aho = false;
	     for (int i = 0; i < gyou; i++) {
        	 //一個でもb[i][j]が#がある
        	 if (b[i][j]) {
        	     aho = true;
        	 }
         }
         //#がある場合
         if (aho) {
        	  for (int i = 0; i < gyou; i++){
        	      c[i][retsu] = b[i][j];
        	  }
        	  retsu++;
         }
	}

	for (int i = 0; i < gyou; i++) {
	    char s[retsu+1];
	    for (int j = 0; j < retsu; j++) {
	        if (c[i][j]) {
	            s[j] = '#';
	        } else {
	            s[j] = '.';
	        }
	    }
	    s[retsu] = '\0';
	    cout << s << endl;
	}

	return 0;
}
