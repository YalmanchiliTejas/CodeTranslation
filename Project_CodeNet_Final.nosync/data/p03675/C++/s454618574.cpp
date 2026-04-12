#include <iostream> 
#include <string> 
#include <vector> 
#include <cmath> 
#include <algorithm> 
#include <cstdlib> 
#include <ctime> 
#include <cstdio> 
#include <functional> 
#include <set> 
#include <sstream> 
#include <cctype>
#include <stack>
#include <queue>
#include <cstring>
#include <map>
 
using namespace std;

int main(){

	int n;
	cin>>n;

	deque<long long> d;

	for(int i=0;i<n;i++){
		long long a;
		cin>>a;
		if(i%2) d.push_front(a);
		else d.push_back(a);
	}

	if(n%2)for(int i=n-1;i>=0;i--) cout<<d[i]<<" ";
	else for(int i=0;i<n;i++) cout<<d[i]<<" ";
	cout<<endl;

	return 0;
}
