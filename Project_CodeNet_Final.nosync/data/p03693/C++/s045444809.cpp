#include <iostream>
#include <cmath>
#include <vector>
#include <queue>
#include <map>
#include <stack>
#include <string>
#include <set>
#include <sstream>
#include <algorithm>
#include <fstream>
#include <deque>
using namespace std;

#define mp make_pair
#define pb push_back
#define ll long long
#define pii pair<int, int>
#define f first
#define s second
#define all(a) a.begin(), a.end()
#define sz(a) (int)a.size()

const int inf = (int)1e9;
const int mod = inf+7;
	
int a, b, c;

int main(){

	cin >> a >> b >> c;
	int num = a*100 + b*10 + c;

	if(num%4==0){
		printf("YES\n");
	}else{
		printf("NO\n");
	}
	return 0;
}