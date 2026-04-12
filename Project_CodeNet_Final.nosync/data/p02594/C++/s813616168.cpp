	//DPCoded
	//

#include <iostream>
#include <fstream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <queue>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef vector<string> vs;
typedef vector<vi> vvi;
typedef vector<vb> vvb;
typedef set<int> si;
typedef set<string> ss;
typedef map<int, int> mii;
typedef map<string, int> msi;
typedef pair<int, int> ii;

//#define FILEINOUT
#ifdef FILEINOUT
ifstream In("Input.txt");
ofstream Out("Output.txt");
#else
#define In cin
#define Out cout
#endif

int main() {
	
	int n;
	In >> n;
	Out << (n >= 30 ? "Yes" : "No");
	
	return 0;
}
