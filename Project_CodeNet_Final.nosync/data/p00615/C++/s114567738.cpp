#include<set>
#include<algorithm>
#define foreach(i, c) for(__typeof(c.begin()) i = c.begin(); i != c.end(); i++)
#define DEBUG
using namespace std;

int main(){
	int m,n;
	while(cin>>m>>n, m||n){
		set<int> t;
		for(int i = 0; i < m+n; i++){
			int a;
			cin>>a;
			t.insert(a);
		}
		set<int> dt;
		int t0; t0 = 0;
		foreach(i, t){
			dt.insert(*i - t0);
			t0 = *i;
		}
		cout<<*(dt.rbegin())<<endl;
	}
	return 0;
}