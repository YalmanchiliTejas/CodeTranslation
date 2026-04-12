#include <iostream>
#include <string>
#include <algorithm> 
#include <cstdlib>
#include <map>
#include <queue>
#include <vector>
#include <utility>
#include <climits>
#include <numeric>
#include <deque>
#define ll long long
#define INF INT_MAX 
using namespace std;
int main(){
	int N;
	cin >> N;
	vector<int> a(N);
	deque<int> ans(1);
	for(int i=0;i<N;i++)cin >> a[i];
	ans[0] = a[0];
	if(N%2==0){
		for(int i=1;i<N;i++){
			if(i%2!=0){
				ans.push_front(a[i]);
			}else{
				ans.push_back(a[i]);
			}
		}
	}else{
		for(int i=1;i<N;i++){
			if(i%2!=0){
				ans.push_back(a[i]);
			}else{
				ans.push_front(a[i]);
			}
		}
	}
	for(int i=0;i<N;i++){
		cout << ans[i] << " ";
	}
	cout << endl;
}