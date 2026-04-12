#include <iostream>
#include <deque>
#include <algorithm>
using namespace std;

int main(){
	int n,sum,t;
	deque<int> deq;
	while(cin >> n , n){
		deq.clear();
		for(int i=0;i<n;i++){
			cin >> t;
			deq.push_back(t);
		}
		
		sort(deq.begin(),deq.end());
		
		deq.pop_back();
		deq.pop_front();
		sum = 0;
		for(int i=0;i<deq.size();i++){
			sum += deq[i];
		}
		cout << sum / deq.size() << endl;
	}
}