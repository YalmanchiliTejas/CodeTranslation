// ConsoleApplication1.cpp : コンソール アプリケーションのエントリ ポイントを定義します。
//


#include <iostream>
#include <vector>
using namespace std;


struct Node
{
	bool path[8];
};
Node nodes[8];
int N, M, sum = 0;


void next(vector<bool> checked, int now)
{
	checked[now] = true;

	bool flag = true;
	for (size_t i = 0; i < N; i++)
	{
		if (!checked[i])
		{
			flag = false;
			break;
		}
	}
	if (flag)
	{
		sum++;
		return;
	}

	for (int i = 0; i < N; i++)
	{
		if (nodes[now].path[i] && !checked.at(i))
		{
			next(checked, i);
		}
	}
}


int main()
{
	cin >> N;
	cin >> M;

	vector<bool> checked(N);

	for (size_t i = 0; i < M; i++)
	{
		int a, b;
		cin >> a;
		cin >> b;
		a--; b--;
		nodes[a].path[b] = true;
		nodes[b].path[a] = true;
	}

	next(checked, 0);
	cout << sum;

}



/*
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	unsigned long long N;
	string s, n;

	cin >> N;
	cin >> s;
	cin >> n;

	unsigned cur = 0;
	for( unsigned i = 0 ; i < s.length() ; i++)
	{
		if (s[i] == n[cur])
			cur++;
		else
		{
			i -= cur;

			cur = 0;
		}
		
	}


	cout << max((unsigned long long)(s.length() + n.length() - cur), N);


}
*/



/*
#include <iostream>
#include <memory>

using namespace std;
int main()
{
	long long x, y, z;
	cin >> x;
	cin >> y;
	cin >> z;

	if(x >= y && x >= z)
	{
		if (x % 2 == 0)
		{
			cout << 0;
			return 0;
		}
		cout << y * z;
	}else if( y >= x && y >= z)
	{
		if (y % 2 == 0)
		{
			cout << 0;
			return 0;
		}
		cout << x * z;
	}else
	{
		if (z % 2 == 0)
		{
			cout << 0;
			return 0;
		}
		cout << x * y;
	}
}*/
/*
int main()
{
	bool n = false, s = false, w = false, e = false;
	while(int c = std::cin.get())
	{
		if (c == EOF)break;
		switch (c)
		{
		case 'N':
			n = true;
			break;
		case 'S':
			s = true;
			break;
		case 'W':
			w = true;
			break;
		case 'E':
			e = true;
			break;
		}
	}

	if (n && s && !e && !w || n && s && e && w || !n && !s && e & w || !n && !s && !w && !e)
	{
		std::cout << "Yes";
	}
	else
	{
		std::cout << "No";
	}

    return 0;
}
*/
