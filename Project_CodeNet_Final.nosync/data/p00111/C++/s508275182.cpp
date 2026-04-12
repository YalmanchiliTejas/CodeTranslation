# define _CRT_SECURE_NO_WARNINGS 1
# include <iostream>
# include <string>
# include <bitset>
# include <vector>
# include <algorithm>
# include <cstdlib>
# include <cstdio>
# include <cstring>
# include <cstdlib>
# include <iomanip>
# include <queue>
# include <sstream>
# include <climits>
# include <cmath>
# include <list>
# include <functional>
# include <string>
# include <set>
# include <map>
# include <stack>
using namespace std;
# define M_PI 3.141592
# define FOR(i,n) for(int i=0;i<(int)n;i++)
# define FORI(i,k,n) for(int i=k;i<(int)n;i++)
# define toRad 2.0*M_PI/360.0
# define inin(x) int x;cin>>x;
# define all(x) x.begin(),x.end()
# define debug(x) cout<<#x<<" :"<<x<<endl;
# define rep(i,n) for(int i=0;i<(int)n;i++)
# define EPS 1e-12
# define pri_max 60000
# define CHECK(i,a) FOR(i,a.size())cout<<#a<<"["<<i<<"] : "<<a[i]<<endl; 
typedef pair<int, int> pii;
typedef pair<double, double> pdd;
typedef vector<int> vi;
typedef vector<vi> vvi;


int main()
{
	map<char, string> enc;
	map<string, char> dec;
	for (char i = 'A'; i <= 'Z'; i++)
	{
		stringstream ss;
		bitset < 5 > b(i-'A');
		ss << b;
		enc.insert(make_pair(i, ss.str()));
	}
	enc[' '] = "11010";
	enc['.'] = "11011";
	enc[','] = "11100";
	enc['-'] = "11101";
	enc['\''] = "11110";
	enc['?'] = "11111";

	dec["101"] = ' ';
	dec["000000"] = '\'';
	dec["000011"] = ',';
	dec["10010001"] = '-';
	dec["010001"] = '.';
	dec["000001"] = '?';
	dec["100101"] = 'A';
	dec["10011010"] = 'B';
	dec["0101"] = 'C';
	dec["0001"] = 'D';
	dec["110"] = 'E';
	dec["01001"] = 'F';
	dec["10011011"] = 'G';
	dec["010000"] = 'H';
	dec["0111"] = 'I';
	dec["10011000"] = 'J';
	dec["0110"] = 'K';
	dec["00100"] = 'L';
	dec["10011001"] = 'M';
	dec["10011110"] = 'N';
	dec["00101"] = 'O';
	dec["111"] = 'P';
	dec["10011111"] = 'Q';
	dec["1000"] = 'R';
	dec["00110"] = 'S';
	dec["00111"] = 'T';
	dec["10011100"] = 'U';
	dec["10011101"] = 'V';
	dec["000010"] = 'W';
	dec["10010010"] = 'X';
	dec["10010011"] = 'Y';
	dec["10010000"] = 'Z';

	string s;
	while (getline(cin,s))
	{
		string x, y, z;
		for (int i = 0; i < s.size(); i++)x += enc[s[i]];

		for (int i = 0; i < x.size(); i++)
		{
			y += x[i];
			if (dec.count(y))
			{
				z += dec[y];
				y = "";
			}
		}
		cout << z << endl;

	}

}