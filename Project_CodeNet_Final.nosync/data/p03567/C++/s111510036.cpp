#include  <functional>
#include  <algorithm>
#include  <exception>
#include  <stdexcept>
#include  <streambuf>
#include  <iterator>
#include  <string.h>
#include  <stdlib.h>
#include  <typeinfo>
#include  <valarray>
#include  <iostream>
#include  <sstream>
#include  <istream>
#include  <stdio.h>
#include  <climits>
#include  <clocale>
#include  <complex>
#include  <csetjmp>
#include  <csignal>
#include  <cstdarg>
#include  <cstddef>
#include  <ctype.h>
#include  <cassert>
#include  <cstdlib>
#include  <utility>
#include  <cstring>
#include  <numeric>
#include  <ostream>
#include  <cwctype>
#include  <fstream>
#include  <iomanip>
#include  <math.h>
#include  <bitset>
#include  <cctype>
#include  <string>
#include  <vector>
#include  <limits>
#include  <locale>
#include  <memory>
#include  <cerrno>
#include  <time.h>
#include  <iosfwd>
#include  <cfloat>
#include  <cstdio>
#include  <cwchar>
#include  <cmath>
#include  <ctime>
#include  <deque>
#include  <queue>
#include  <stack>
#include  <list>
#include  <ios>
#include  <map>
#include  <set>
#include  <new>
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define ll long long
#define pii pair<int,int>
using namespace std;
string s;
int main()
{
    cin>>s;
    for(int i=0;i<s.size()-1;i++)
    {
        if(s[i]=='A' && s[i+1]=='C')
        {cout<<"Yes";return 0;}
    }
    cout<<"No";
    return 0;
}
