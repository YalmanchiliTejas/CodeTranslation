/*
 
*/
#include <iostream>
#include <cmath>
#include <algorithm>
#include <string>
#include <vector>
#include <iomanip>
#include <set>
#include <map>
#include <stack>
#include <deque>
 
#define ll long long
#define cint const int
#define ld long double
#define sz(a) (int)a.size()
#define all(a) a.begin(), a.end()
#define pb push_back
#define ppb pop_back
#define fi first
#define se second
 
using namespace std;
 
typedef vector <long long> vll;
typedef vector <string> vs;
typedef vector <char> vc;
typedef set <int> si;
typedef set <string> ss;
typedef pair <int, int> pi;
typedef pair <long long, long long> pll;
typedef pair <int, long long> pil;
typedef pair <int, string> pis;
typedef pair <int, char> pic;
typedef pair <long long, int> pli;
typedef pair <long long, string> pls;
typedef pair <long long, char> plc;
typedef pair <string, int> psi;
typedef pair <string, long long> psl;
typedef pair <string, char> psc;
typedef pair <char, int> pci;
typedef pair <char, long long> pcl;
typedef pair <char, string> pcs;
 
int n, m;
 
int main () {
	cin >> n >> m;
	if (n == m) {
    	cout << "Yes";
      	return 0;
    }
  	cout << "No";
	return 0;
}