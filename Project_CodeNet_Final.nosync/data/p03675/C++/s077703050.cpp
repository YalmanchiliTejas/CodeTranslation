#include <iostream>
#include <list>
using namespace std;
   
int main(){
	int N;
	cin >> N;
	list<int> array_b;
	string ans = "";
	for(int i = 0; i < N; i++){
		int array_a;
		cin >> array_a;
		if(i % 2 == 0){
			array_b.push_back(array_a);
		}else{
			array_b.push_front(array_a);
		}
	}
	if(N % 2 == 0){
		for(int i = 0; i < N; i++){
			ans += to_string(array_b.front()) + " ";
			array_b.pop_front();
		}
	}else{
		for(int i = 0; i < N; i++){
			ans += to_string(array_b.back()) + " ";
			array_b.pop_back();
		}
	}
	ans.pop_back();
	cout << ans << endl;
}