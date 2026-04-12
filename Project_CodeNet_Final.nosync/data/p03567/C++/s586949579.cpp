#include <iostream>
#include <fstream>
#include <cstdio>
#include <cassert>
#include <complex>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <cstdlib>
#include <cstring>
#include <iomanip>
#include <numeric>
#include <sstream>
#include <ctime>
#include <cctype>
#include <set>
#include <map>
#include <queue>
#include <bitset>
#include <deque>
#include <stack>
#include <memory.h>
using namespace std;
#define ll long long 
string s;
int main()
{
	cin>>s;
	for(int i=0;i<s.size()-1;i++){
		if(s[i]=='A'&&s[i+1]=='C'){
			cout<<"Yes";
			return 0;
		}
	}
	cout<<"No";
    return 0;
}