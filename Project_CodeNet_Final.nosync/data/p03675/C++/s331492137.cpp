#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <functional>

using namespace std;
#define FOR(i,a,b) for (int i=(a);i<(b);i++)
#define RFOR(i,a,b) for (int i=(b)-1;i>=(a);i--)
#define REP(i,n) for (int i=0;i<(n);i++)
#define RREP(i,n) for (int i=(n)-1;i>=0;i--)
#define VI vector<int>
#define debug(x) cout<<#x<<": "<<x<<endl
#define DEBUG(x) cout<<#x<<": "<<x<<endl
int N;
vector <int > a,ans1,ans2;





int main()
{

	cin >> N;

	a.resize(N);
	REP(i,N){
		cin >> a[i];
	}
	int flag=0;
	RREP(i,N){
		vector<int>::iterator it;
		if(flag==0){
			ans1.push_back(a[i]);
			flag=1;
		} else {
			it = ans2.begin();
			ans2.insert(it,a[i]);
			flag=0;
		}
	}

	REP(i,ans1.size()){
			cout << ans1[i] << " ";
	}
	REP(i,ans2.size()){
			cout << ans2[i] << " ";
	}

}


