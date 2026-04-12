#if __cplusplus >= 201103L
#pragma comment(linker, "/STACK:64000000")
#define _CRT_SECURE_NO_WARNINGS
#endif
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <ctime>
#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <algorithm>
#include <string>
#include <vector>
#include <list>
#include <deque>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <bitset>
#include <valarray>
#include <utility>
#include <cctype>
#include <numeric>
#if __cplusplus >= 201103L
#include <cwchar>
#include <cwctype>
#include <array>
#include <forward_list>
#include <unordered_map>
#include <unordered_set>
#endif
using namespace std;
const int MAXN=200005;
int n,a[MAXN]; 
deque<int> v;
int main(){
	cin>>n;
	for(int i=0;i<n;++i) {
		cin>>a[i];
		if(i%2==0) v.push_front(a[i]);
		else v.push_back(a[i]);
	}
	if(n%2==0) reverse(v.begin(),v.end());
	for(int i=0;i<n;++i) cout<<v[i]<<" ";
	cout<<endl;
	return 0;
}
