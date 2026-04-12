#include<iostream>
#include<vector>
#include<string>
using namespace std;

int main()
{
	int H, W;
	cin >> H >> W;

	vector<string> a(H);
	for (int i = 0; i < H; i++)
		cin >> a.at(i);

	int count;
	vector<int> b(100);
	int bcou = 0;

	for (int i = 0; i < H; i++) {
		count = 0;
		for (int j = 0; j < W; j++) {
			if (a[i][j] == '.')
				count++;
			if (count == W) {
				b.at(bcou) = i;
				bcou++;
			}
		}
	}

	for (int i = 0; i < W; i++) {
		count = 0;
		for (int j = 0; j < H; j++) {
			if (a[j][i] == '.')
				count++;
			if(count==H){
				for (int k = 0; k < H; k++) {
					a[k].at(i)='0';
				}
			}
		}
	}

	int j = 0;
	for (int i = 0; i < H; i++) {
		for (j = 0; j < W; j++) {
			if (a[i].at(j) == '0')
				continue;
			for (int k = 0; k < bcou; k++) {
				if (i == b.at(k)) {
					j = W+1;
					break;
				}
			}
			if (j != W + 1)
				cout << a[i].at(j);
		}
		if (j == W)
			cout << endl;
	}
    return 0;
}