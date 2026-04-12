#include<iostream>
#include<sstream>
#include<fstream>
#include<string>
#include<vector>
#include<deque>
#include<queue>
#include<stack>
#include<set>
#include<map>
#include<algorithm>
#include<functional>
#include<utility>
#include<bitset>
#include<cmath>
#include<cstdlib>
#include<ctime>
#include<cstdio>
#include<cstring>
using namespace std;
deque<int> a;
bool dir;
int n,x;
int main(){
	cin>>n;
	if (n%2==0) dir=false;else dir=true;
	for (int i=0;i<n;i++){
		cin>>x;
		if (dir) a.push_front(x);
		else a.push_back(x);
		dir^=1;
	}
	for (int i=0;i<a.size()-1;i++)	cout<<a[i]<<" ";
	cout<<a[a.size()-1];
	return 0;
}