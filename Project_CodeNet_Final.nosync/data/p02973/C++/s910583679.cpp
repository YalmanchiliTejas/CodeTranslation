#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <string>
#include <sstream>
#include <utility>
#define ll long long int
#define rep(i,x,y) for(int i=x;i<y;i++)
#define rel(i,x,y) for(int i=x-1;i>=y;i--)
#define all(x) x.begin(),x.end()

using namespace std;

int main(){
	int N;
	cin >> N;
	vector<int> A(N);
	vector<int> ans;
	rep(i,0,N) cin >> A[i];
	ans.push_back(A[0]);
	rep(i,1,N){
		if(ans.front()>=A[i]){
			ans.insert(ans.begin(),A[i]);
		}else if(ans.back()<A[i]){
			ans[ans.size()-1] = A[i];
		}else{
			auto itr = lower_bound(all(ans),A[i]);
			--itr;
			*itr = A[i];
		}
	}
	cout << ans.size() << endl;
}
