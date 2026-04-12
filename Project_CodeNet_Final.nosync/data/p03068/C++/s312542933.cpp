#include<bits/stdc++.h>#include<algorithm>
#include<clocale>
#include<cmath>
#include<complex>
#include<csetjmp>
#include<csignal>
#include<cstdarg>
#include<cstddef>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<ctime>
#include<deque>
#include<iostream>
#include<istream>
#include<map>
#include<math.h>
#include<ostream>
#include<queue>
#include<set>
#include<sstream>
#include<stack>
#include<string>
#include<vector>
using namespace std;
int n,k;
string s;
int main(){
	cin>>n>>s>>k;
	for (int i=0;i<s.size();i++) if (s[i]!=s[k-1]) s[i]='*';
	cout<<s<<endl;
	return 0;
}