#include <iostream>
#include <sstream>
#include <iomanip>
#include <vector>
#include <deque>
#include <list>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <bitset>
#include <string>
#include <numeric>
#include <algorithm>
#include <functional>
#include <iterator>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <complex>
#include <ctime>
#define ll long long
#define inf 0x3f3f3f3f
#define N 100010
//ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;

int main(){
	int n,a;
	vector<int> v;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
    {
        scanf("%d",&a);
        a*=-1;
        int it=upper_bound(v.begin(),v.end(),a)-v.begin();
        if(it==v.size())
        {
            v.push_back(a);
        }
        else
            v[it]=a;
    }
    printf("%d\n",v.size());
	return 0;
}
