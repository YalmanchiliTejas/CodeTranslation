#include <iostream>
#include <unordered_map>
#include <vector>
#include <set>
#include <string.h>
#include <algorithm>
#define mod 1000000007
#define inf 1LL<<61
#define ll long long
#define pr pair<int,int>
#define all vec.begin(),vec.end()
#define rep(i,a,b) for (int i = a; i < b; i++)
#define fi first
#define se second
#define pushb push_back
#define makep make_pair

using namespace std;

int main(){
	int a,b,c;
	cin >> a >> b >> c;
	int res = a * 100 + b *10 + c;
	if(res % 4 == 0)
		cout << "YES";
	else 
		cout << "NO";
	return 0;
}

