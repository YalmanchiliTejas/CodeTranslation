#include <vector>
#include <map>
#include <string>
#include <iostream>
#include <cmath>
#include <random>
#include <cctype>
#include <cstdlib>
#include <algorithm>
using namespace std;
#define MK make_pair
#define PB push_back
#define VI vector<int>
#define VII vector<int,int>
#define MSI map<string,int>
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)
#define W1 while(1);
const int MOD = 1000000007;
int main()
{
	int N;
	cin >> N;
	cout << (N * 800) - (N / 15 * 200) << endl;
	return 0;
}