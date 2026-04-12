#include<stdio.h>
#include<iostream>
#include<fstream>
#include<vector>
#include <bitset>

using namespace std;

inline int rev(int i, int N)
{
	return N - i - 1;
}


int main(){
	std::istream & c_in = cin;
	int N;
	c_in >> N;
	vector<int> sub;
	sub.resize(N / 2);

	for (int i = 0; i < N / 2; ++i)
	{
		c_in >> sub[i];
	}

	int count = 0;
	int j = N - N / 2 - 1;
	for (int i = N / 2; i < N; ++i)
	{
		int dat;
		c_in >> dat;
		sub[j] -= dat;
		count += (sub[j--] == 0);

	}
	bool b_same = (count == N / 2);

	int Q;
	c_in >> Q;

	for (int q = 0; q < Q; ++q)
	{
		int L, r, x;
		c_in >> L >> r >> x;
		if (x != 0)
		{
			//??°??????l????????????r???????????§??????????????????????´??????°???x????¶????
			//1???l???r???N
			L--;	//base 0
			r--;	//base 0

			int s, t;
			if (r < N / 2)
			{
				s = L;
				t = r;
			}
			else if (L >= N / 2)
			{
				s = rev(r, N);
				t = rev(L, N);
				x = -x;
			}
			else
			{
				r = rev(r, N);
				if (L < r)
				{
					s = L;
					t = r - 1;
				}
				else
				{
					s = r;
					t = L - 1;
					x = -x;
				}
			}
			if (s <= t)
			{
				int * p = &sub[s];
				for (int i = s; i <= t; ++i,++p)
				{
					int v = *p;
					bool pre = (v == 0);
					v += x;
					bool same = (v == 0);
					*p = v;
					if (pre != same)
					{
						count += same - pre;
					}
				}
				b_same = (count == N / 2);
			}

		}
		cout << (b_same ? '1' : '0') << endl;

	}
}