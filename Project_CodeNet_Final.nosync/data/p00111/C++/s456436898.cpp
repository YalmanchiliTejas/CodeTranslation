#include <iostream>
#include <cstdio>
#include <cstring>
#include <sstream>
#include <algorithm>
#include <math.h>
#include <map>
#include <functional>
#include <iomanip>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <typeinfo>
#define PI 3.14159265359
#define INF 99999999
#define rep(i, n) for(int i=0; i<n; i++)
#define REP(n) rep(i, n)
#define EPS 1e-10
#define pb push_back
#define mp make_pair
typedef long long ll;
using namespace std;
typedef pair<int, int> P;

bool isLeap(int y);
ll gcd(ll a, ll b);
ll lcm(ll a, ll b);
double distanceAB(double xa, double ya, double xb, double yb);
void trace(int A[], int N);

/*
class Target
{
public:
	vector <string> draw(int n)
	{

	}
};
*/


string getConversion1(string inp)
{
	string ret = "";
	map<char, string> tbl;
	
	tbl['A'] = "00000";
	tbl['B'] = "00001";
	tbl['C'] = "00010";
	tbl['D'] = "00011";
	tbl['E'] = "00100";
	tbl['F'] = "00101";
	tbl['G'] = "00110";
	tbl['H'] = "00111";
	tbl['I'] = "01000";
	tbl['J'] = "01001";
	tbl['K'] = "01010";
	tbl['L'] = "01011";
	tbl['M'] = "01100";
	tbl['N'] = "01101";
	tbl['O'] = "01110";
	tbl['P'] = "01111";
	tbl['Q'] = "10000";
	tbl['R'] = "10001";
	tbl['S'] = "10010";
	tbl['T'] = "10011";
	tbl['U'] = "10100";
	tbl['V'] = "10101";
	tbl['W'] = "10110";
	tbl['X'] = "10111";
	tbl['Y'] = "11000";
	tbl['Z'] = "11001";
	tbl[' '] = "11010";
	tbl['.'] = "11011";
	tbl[','] = "11100";
	tbl['-'] = "11101";
	tbl['\''] = "11110";
	tbl['?'] = "11111";
	
	rep(i, inp.length())
	{
		ret += tbl[inp[i]];
	}
	
	return ret;
}

string getConversion2(string inp)
{
	string ret = "", key = "";
	map<string, char> tbl;
	
	tbl["101"] = ' ';
	tbl["000000"] = '\'';
	tbl["000011"] = ',';
	tbl["10010001"] = '-';
	tbl["010001"] = '.';
	tbl["000001"] = '?';
	tbl["100101"] = 'A';
	tbl["10011010"] = 'B';
	tbl["0101"] = 'C';
	tbl["0001"] = 'D';
	tbl["110"] = 'E';
	tbl["01001"] = 'F';
	tbl["10011011"] = 'G';
	tbl["010000"] = 'H';
	tbl["0111"] = 'I';
	tbl["10011000"] = 'J';
	tbl["0110"] = 'K';
	tbl["00100"] = 'L';
	tbl["10011001"] = 'M';
	tbl["10011110"] = 'N';
	tbl["00101"] = 'O';
	tbl["111"] = 'P';
	tbl["10011111"] = 'Q';
	tbl["1000"] = 'R';
	tbl["00110"] = 'S';
	tbl["00111"] = 'T';
	tbl["10011100"] = 'U';
	tbl["10011101"] = 'V';
	tbl["000010"] = 'W';
	tbl["10010010"] = 'X';
	tbl["10010011"] = 'Y';
	tbl["10010000"] = 'Z';
	
	rep(i, inp.length())
	{
		key += inp[i];
		if (tbl.find(key) != tbl.end())
		{
			ret += tbl[key];
			key = "";
		}
	}
	
	return ret;
}


int main()
{
	string inp, conv, ans;
	
	while (getline(cin, inp))
	{
		conv = getConversion1(inp);
		
		//cout << conv << endl;
		
		ans = getConversion2(conv);
		
		cout << ans << endl;
	}
	
	return 0;
}


bool isLeap(int y)
{
	return y % 400 == 0
						? true : y % 100 == 0
						? false : y % 4 == 0
						? true : false;
}

ll gcd(ll a, ll b)
{
	return (b > 0) ? gcd(b, a % b) : a;
}

ll lcm(ll a, ll b)
{
	return a / gcd(a, b) * b;
}

void trace(int A[], int N)
{
	REP(N)
	{
		if (i > 0) cout << " ";
		cout << A[i];
	}
	cout << endl;
}

double distanceAB(double xa, double ya, double xb, double yb)
{
	return sqrt((xb-xa)*(xb-xa) + (yb-ya)*(yb-ya));
}