#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <bitset>
using namespace std;

typedef long long ll;
typedef pair<int,int> P;
typedef pair<int,P> P2;
const int inf=1000000000;
int main() {
	int n;
	int a[200001]={};
	cin>>n;
	for(int i=0;i<n;++i)cin>>a[i];
	cout<<a[n-1];
	for(int i=n-3;i>=0;i-=2)cout<<" "<<a[i];
	for(int i=(n%2);i<=n-2;i+=2)cout<<" "<<a[i];
	cout<<endl;
	return 0;
}
