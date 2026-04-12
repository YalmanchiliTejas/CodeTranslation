#include <iostream>
#include <set>
#define MAX(a,b) ((a>b)?(a):(b))
using namespace std;

int main(void){
	int n,m;
	int a;
	while(cin>>n>>m,n||m){
		std::multiset<int> ms;
		for(int i=0;i<n+m;i++)cin>>a,ms.insert(a);
		int m=*(ms.begin());
		for(__typeof(ms.begin()) it=++ms.begin(),b=ms.begin();it!=ms.end();it++,b++){
			m=MAX(m,*it-*b);
		}
		cout<<m<<endl;
	}
	return 0;
}