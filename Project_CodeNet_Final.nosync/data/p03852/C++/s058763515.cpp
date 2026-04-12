#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<cmath>
#include<map>
#include<cstdio>
#include<stack>
#include<queue>
#include<fstream>
#include<cstdio>

using namespace std;
#define ok1 printf("ok1\n");
#define ok2 printf("ok2\n");
#define M 100000000
#define rep(i,n) for(int i=0;i<n;i++)
#define REP(i,s,n) for(int i=(s);i<(n);i++)
#define repr(i,n) for(int i=n-1;i>=0;i--)
#define REPR(i,s,n) for(int i=(s);i>=(g);(i)--)
#define all(a) (a).begin(),(a).end()
#define reall(a) (a).rbegin(),(a).rend()
#define pb push_back
#define MIN(a,b) a=min((a),(b))
#define MAX(a,b) a=max((a),(b))
#define SIZE(v) (int)v.size()
const double PI = acos(-1.0);

typedef vector<int> vi;
typedef vector<string> vs;
typedef long long ll;
typedef vector<ll> vll;
typedef vector<vi> vvi;


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	string s;
	cin >> s;
	if (s == "a" || s == "e" || s == "i" || s == "o" || s == "u")
		cout << "vowel";
	else
		puts("consonant");
	return 0;
}