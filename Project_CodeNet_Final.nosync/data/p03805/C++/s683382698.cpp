#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <string>
#include <cmath>
#include <cstdio>
#include <cctype>
#include <ctime>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <cctype>
#include <cerrno>
#include <cfloat>
#include <ciso646>
#include <climits>
#include <clocale>
#include <complex>
#include <csetjmp>
#include <csignal>
#include <cstdarg>
#include <cstddef>
#include <cwchar>
#include <cwctype>
#include <exception>
#include <locale>
#include <numeric>
#include <new>
#include <stdexcept>
#include <limits>
#include <valarray>
#include <set>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <map>
#include <list>
#include <utility>
#include <bitset>
#include <algorithm>
#include <functional>
#define rep(i,n) for(int i=0;i<(n);i++)
#define rep1(i,n) for(int i=1;i<=(n);i++)
#define MP make_pair
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int INF=1e9+7;
bool con[10][10];
int n,a[10]={1,2,3,4,5,6,7,8,9,10};
bool check(){
	rep(k,n-1)if(!con[a[k]][a[k+1]])return false;
	return true;
}
int main(){
	ios::sync_with_stdio(false);
	int m,x,y,ans=0;
	cin>>n>>m;
	rep(k,m){
		cin>>x>>y;
		con[x][y]=con[y][x]=true;
	}
	do{
		if(check())ans++;
	}while(next_permutation(a+1,a+n));
	cout<<ans<<endl;
	return 0;
}