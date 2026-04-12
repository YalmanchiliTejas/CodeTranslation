//Written by Zhu Zeqi
//Come on,baby
//Hack,please
#include<cmath>
#include<math.h>
#include<ctype.h>
#include<algorithm>
#include<bitset>
#include<cassert>
#include<cctype>
#include<cerrno>
#include<cfloat>
#include<ciso646>
#include<climits>
#include<clocale>
#include<complex>
#include<csetjmp>
#include<csignal>
#include<cstdarg>
#include<cstddef>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<ctime>
#include<cwchar>
#include<cwctype>
#include<deque>
#include<exception>
#include<fstream>
#include<functional>
#include<iomanip>
#include<ios>
#include<iosfwd>
#include<iostream>
#include<istream>
#include<iterator>
#include<limits>
#include<list>
#include<locale>
#include<map>
#include<memory>
#include<new>
#include<numeric>
#include<ostream>
#include<queue>
#include<set>
#include<sstream>
#include<stack>
#include<stdexcept>
#include<streambuf>
#include<string>
#include<typeinfo>
#include<utility>
#include<valarray>
#include<vector>
#include<string.h>
#include<stdlib.h>
#include<stdio.h>
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define pii pair<int,int>
#define vi vector<int>
#define MAX 100000000000000000
#define MOD 1000000007
#define PI 3.141592653589793238462
#define INF 1000000000
typedef long long ll;
using namespace std;
//作者：中国江苏南京朱泽齐
bool good[10][10];
int n,a[10]={1,2,3,4,5,6,7,8,9,10};
bool check(){
	for(int i=0;i<n-1;i++)
	if(!good[a[i]][a[i+1]])
	return false;
	return true;
}
int main(){
	//freopen("input.in","r",stdin);
	//freopen("output.out","w",stdout);
	int m,x,y,ans=0;
	cin>>n>>m;
	for(int i=0;i<m;i++){
		cin>>x>>y;
		good[x][y]=good[y][x]=true;
	}
	do{
		if(check())
		ans++;
	}while(next_permutation(a+1,a+n));
	cout<<ans<<endl;
	//system("pause");
	return 0;
}