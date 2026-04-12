#include <bits/stdc++.h>
using namespace std;

#define fastIO ios::sync_with_stdio(false);cout.tie(0);cin.tie(0);
#define endl '\n'
#define pb push_back
#define pf push_front
#define fi first
#define se second
#define MP make_pair
#define inf INT_MAX
#define minf INT_MIN

typedef long long int lli;

ofstream outfile;
ifstream infile;

int n;
int data[100002];
string s;

bool checker()
{
	int i;
	for(i = 2; i < n-1; ++i)
	{
		if(data[i] == 1)
		{
			if(s[i-1] == 'o')
				data[i+1] = data[i-1];
			else{
				if(data[i-1] == 1)
					data[i+1] = 2;
				else
					data[i+1] = 1;
			}
		}
		else
		{
			if(s[i-1] == 'x')
				data[i+1] = data[i-1];
			else
			{
				if(data[i-1]==1)
					data[i+1] = 2;
				else
					data[i+1] = 1;
			}
		}
	}
	if(data[n] == 1)
	{
		if(s[n-1] == 'o')
		{
			if(data[1] != data[n-1])
				return false;
		}
		else
		{
			if(data[1] == data[n-1])
				return false;
		}
	}
	else
	{
		if(s[n-1] == 'x')
		{
			if(data[1] != data[n-1])
				return false;
		}
		else
		{
			if(data[1] == data[n-1])
				return false;
		}
	}
	if(data[n-1] == 1)
	{
		if(s[n-2] == 'o')
		{
			if(data[n-2] != data[n])
				return false;
		}
		else
		{
			if(data[n-2] == data[n])
				return false;
		}
	}
	else
	{
		if(s[n-2] == 'x')
		{
			if(data[n-2] != data[n])
				return false;
		}
		else
		{
			if(data[n-2] == data[n])
				return false;
		}
	}

	if(data[1] == 1)
	{
		if(s[0] == 'o')
		{
			if(data[2] == data[n])
				return true;
			return false;
		}
		else
		{
			if(data[2] != data[n])
				return true;
			return false;
		}
	}
	else
	{
		if(s[0] == 'x')
		{
			if(data[2] == data[n])
				return true;
			return false;
		}
		else
		{
			if(data[2] != data[n])
				return true;
			return false;
		}
	}
}

void print()
{
	for(int i = 1; i <= n; ++i)
	{
		if(data[i] == 1)
			cout << 'S';
		else
			cout << 'W';
	}
	cout << "\n";
}
int main()
{
	infile.open("input.txt");
	outfile.open("output.txt");

	cin >> n >> s;

	data[1] = 1;
	if(s[0] == 'o')
	{
		data[n] = 1;
		data[2] = 1;
		if(checker())
		{
			print();
			return 0;
		}
		data[n] = 2;
		data[2] = 2;
		if(checker())
		{
			print();
			return 0;
		}
	}
	else
	{
		data[2] = 2;
		data[n] = 1;
		if(checker())
		{
			print();
			return 0;
		}
		data[2] = 1;
		data[n] = 2;
		if(checker())
		{
			print();
			return 0;
		}
	}

	data[1] = 2;
	if(s[0] == 'x')
	{
		data[2] = 2;
		data[n] = 2;
		if(checker())
		{
			print();
			return 0;
		}
		data[2] = 1;
		data[n] = 1;
		if(checker())
		{
			print();
			return 0;
		}
	}
	else
	{
		data[2] = 2;
		data[n] = 1;
		if(checker())
		{
			print();
			return 0;
		}

		data[2] = 1;
		data[n] = 2;
		if(checker())
		{
			print();
			return 0;
		}
	}
	cout << "-1\n";
	return 0;
}