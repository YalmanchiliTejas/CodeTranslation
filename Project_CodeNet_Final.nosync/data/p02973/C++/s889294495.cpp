#include <iostream>
#include <sstream>
#include <vector>
#include <utility>
#include <map>
#include<set>
#include <algorithm>
#include <string>
#include <string.h>
#include <iomanip>
#include <cmath>
#define ll long long
#define PI 3.14159265358979323846
#define lp(i, n) for (long long i = 0; i < n; i++)
#define rep(i, v) for (int i = 0; i < int(v.size()); i++)
using namespace std;
int main(){
	int n;
	cin>>n;
	multiset<int> ms;
	lp(i,n)
	{
		int a;
		cin>>a;
		auto it=ms.lower_bound(a);
		if(it==ms.begin())
			ms.insert(a);
		else
			{
				it--;
				ms.erase(it);
				ms.insert(a);	
			}
	}	
	cout<<ms.size();					
	return 0;
}