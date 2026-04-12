#include <iostream>
#include <string>
#include <list>
#include <vector>
#include <set>
#include <unordered_set>
#include <stack>
#include <algorithm>
#include <queue>
#include <ctime>
#include <iomanip>
#include <tuple>
#include <functional>
#include <map> 
#include <numeric> 
#include <math.h>
 
using namespace std;
 
 
#define ll long long
#define pi pair<int, int>
#define vi vector<int>
#define vp vector<pi>
#define msa(A, a, n) memset(A, a, n*sizeof(A))
#define msv(A, a) fill(A.begin(), A.end(), a);
#define msc(A, n) memset(A, '\0', n)
#define rep_itr(itr, c) for(itr = (c).begin(); itr != (c).end(); itr++)
#define rep(i, a, b) for(int i = a; i < b; i++)
#define per(i, a, b) for(int i = a; i >= b; i--)
#define pern(i, b) per(i, b - 1, 0)
#define repn(i, b) rep(i, 0, b)
#define repe(i, a, b) for(int i = a; i <= b; i++)
#define repen(i, b) repe(i, 1, b)
#define fast ios_base::sync_with_stdio();cin.tie(0);
#define endl "\n"
//#define MYDEBUG 
 
void my_return(int code)
{
#ifdef MYDEBUG
	std::cout << "\n\nTime = " << fixed << std::setprecision(3) << double(clock()) / CLOCKS_PER_SEC << endl;
#endif
	exit(code);
}
 
int main()
{
	fast
#ifdef MYDEBUG
		freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
 
	int n;
	cin >> n;
	cout << ((n >= 30) ? "Yes" : "No");
 
	my_return(0);
 
}