#include <deque>
#include <iostream>
using namespace std;

int main(){
	
	deque<int> dp;
	
	int n;
	cin >> n;
	
	if(n%2){
		for(int i = 0; i < n; i++){
			int t; 
			cin >> t;
			if(i%2){
				dp.push_back(t);
			}else{
				dp.push_front(t);
			}
		}
	}else{
		for(int i = 0; i < n; i++){
			int t; 
			cin >> t;
			if(i%2==0){
				dp.push_back(t);
			}else{
				dp.push_front(t);
			}
		}
	}
	
	for(int i = 0; i < n; i++)
		cout << dp[i] << (i == n-1? '\n' : ' ');
	
}