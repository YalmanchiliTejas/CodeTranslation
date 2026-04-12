#include <iostream>

#include <vector>

#include <algorithm>

#include <sstream>

#include <string>

#include <cmath>

#include <list>

#include <set>
using namespace std;

int in() {int x; cin >> x; return x;}

template <typename T> class SegTree

{

public:

	int n;

	T T_max;

	vector<T> dat;

	SegTree(int n_, T t_max)

	{

		int n = 1;

		T_max = t_max;

		while (n < n_)n *= 2;

		for (int i = 0; i < 2 * n - 1; i++)dat.push_back(t_max);

	}

	void update(int k, T a)

	{

		k += n - 1;

		dat[k] = a;

		while (k > 0)

		{

			k = (k - 1) / 2;

			dat[k] = min(dat[k * 2 + 1], dat[k * 2 + 2]);

		}

	}



	//[a,b)

	T query(int a, int b)

	{

		return _query(a, b, 0, 0, n);

	}



private:

	T _query(int a, int b, int k, int l, int r)

	{

		if (r <= a || b <= l)return T_max;

		if (a <= l && r <= b)return dat[k];

		else

		{

			T vl = _query(a, b, k * 2 + 1, l, (l + r) / 2);

			T vr = _query(a, b, k * 2 + 2, (l + r) / 2, r);

			return min(vr, vl);

		}

	}

};

int main()
{
	int n;
	bool fis = true;
	while (cin >> n && n)
	{
		if (fis)
		{
			fis = false;
		}
		else
		{
			cout << endl;
		}
		vector< pair <int, string> > a;
		for (int i = 0; i < n; i++)
		{
			int p = 0;
			string name;
			cin >> name;
			p += in() * 3; in();
			p += in();

			a.push_back(pair<int, string>(p, name));
		}

		for (int l = 0; l <= n; l++)
		{
			for (int i = 1; i < a.size(); i++)
			{
				if (a[i].first > a[i - 1].first)swap(a[i], a[i - 1]);
			}
		}

		for (int i = 0; i < n; i++)
		{
			cout << a[i].second << "," << a[i].first << endl;
		}
	}
}