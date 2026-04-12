#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <iostream>
#include <cmath>
#include <string>
#include <algorithm>
#include <set>
#include <map>
#include <cstring>
#include <vector>
#include <stack>
#include <deque>
#include <queue>
#include <cstdlib>
#include <iomanip>
#include <unordered_map>
#include <unordered_set>
typedef long long int ll;
#define forn for(int i=0;i<n;i++) 
#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define form for(int j=0;j<m;j++) 
#define fora(i,a,b) for(int i = a; i < (b); i++)
#define pb push_back 
#define mp make_pair 
#define sc second 
#define f first 
#define kek cout<<"\n" 
#define all(v) ((v).begin()), ((v).end()) 
#define pob pop_back() 
const ll MOD = 1e9 + 7;
const int N = 1005;
const ll INF = 1e9;
using namespace std;
int main()
{
#if defined(_DEBUG)
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	fast;
	//string al = "abcdefghijklmnopqrstuvwxyz";
	string s;
	cin >> s;
	sort(all(s));
	if (s[0] == s[2]) cout << "No";
	else cout << "Yes";
	return 0;

}