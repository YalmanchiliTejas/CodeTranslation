#include<iostream>
#include<iomanip>
#include<set>
#include<vector>
#include<cmath>
#include<complex>
#include<string>
#include<algorithm>

using namespace std;

#define rep(i,n) for(int i=0;i<n;i++)
#define pb push_back

typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<vi> vvi;


int main(void)
{
  int n;
	string l;
	int k;
	cin >> n >> l >> k;
	char m = l[k-1];
	rep(i,n){
		if(l[i] != m) l[i] = '*';
	}
	cout << l << endl;

  return 0;
}
