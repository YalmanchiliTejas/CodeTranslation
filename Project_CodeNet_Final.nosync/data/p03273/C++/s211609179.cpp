#include "bits/stdc++.h"
using namespace std;
 
int main(void) {
    int h, w;
    cin >> h >> w;

    string a[h];

    for(int i=0;i<h;i++) {
        cin >> a[i];
    }

	bool check;

	for(int i=0;i<h;i++) {
		check = true;
		for(int j=0;j<w;j++) {
			if(a[i].at(j) == '#') check = false;
		}
		if(check == true) {
			for(int k=i;k<h-1;k++) {
				a[k] = a[k+1];
			}
			i--;
			h--;
		}
	}

	for(int i=0;i<w;i++) {
		check = true;
		for(int j=0;j<h;j++) {
			if(a[j].at(i) == '#') check = false;
		}
		if(check == true) {
			for(int k=0;k<h;k++) {
				a[k].erase(a[k].begin() + i);
			}
			i--;
			w--;
		}
	}

	for(int i=0;i<h;i++) {
		cout << a[i] << endl;
	}
}
