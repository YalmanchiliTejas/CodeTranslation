#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <map>
#define N 100005
using namespace std;
typedef long long ll;
int n;
int main() {
	cin>>n;
	int res = n * 800;
	cout<<res-(n/15)*200<<endl;
	return 0;
}