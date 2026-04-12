#include<iostream>
#include<sstream>
#include<vector>
#include<iterator>
#include<algorithm>
using namespace std;

#define WHITE '.'
#define BLACK '#'
#define NONE ' '

int main(void)
{
	int H, W;
	cin >> H >> W;

	vector<string> a(H);
	for(int i=0; i<H; i++)
		cin >> a[i];

	vector<bool> h(H, true), w(W, true);
	for(int i=0; i<H; i++){
		int cnt = count(a[i].begin(), a[i].end(), BLACK);
		if(cnt == 0)
			h[i] = false;
	}
	for(int i=0; i<W; i++){
		int cnt = 0;
		for(int j=0; j<H; j++)
			cnt += (a[j][i] == BLACK);
		if(cnt == 0)
			w[i] = false;
	}

	for(int i=0; i<H; i++){
		if(h[i] == false)
			continue;

		for(int j=0; j<W; j++)
			if(w[j] == true) cout << a[i][j];

		cout << endl;
	}

	return 0;
}
