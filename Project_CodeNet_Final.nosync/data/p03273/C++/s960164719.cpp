#include<cstdio>
#include<iostream>
#include<string>
#include<vector>

using namespace std;

int main(void) {

	int h, w;

	string tmp;

	cin >> h >> w;

	vector<string> a, st(w);

	bool delet = false;

	for (int ih = 0; ih < h; ih++)
	{
		cin >> tmp;
		a.push_back(tmp);
		/*for (int iw = 0; iw < w; iw++)
		{
			st[iw][ih] = a[ih][iw];
		}*/
	}

	for (int iw = 0; iw < w; iw++)
	{
		delet = false;

		for (int ih = 0; ih < h; ih++)
		{
			if (a[ih][iw] == '#')break;
			if (ih == h - 1)delet = true;
		}

		if (delet) {
			for (int ih = 0; ih < h; ih++)
			{
				a[ih].erase(a[ih].begin() + iw);
			}
			w--;
			iw--;
		}
	}

	for (int ih = 0; ih < h; ih++)
	{
		string b(w,'.');
		if (equal(a[ih].begin(), a[ih].begin()+w, b.begin())) {
			a.erase(a.begin() + ih);
			h--;
			ih--;
		}
	}


	cout << "\n";
	for (int ih = 0; ih < h; ih++)
	{
		cout << a[ih]<<"\n";
	}



	return 0;
}