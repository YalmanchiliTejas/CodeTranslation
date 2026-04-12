#include <bits/stdc++.h>
using namespace std;
int main(){
	int N; cin >> N;
  	multiset<int> act;
  	int t;
  	for(int i = 0; i < N; i ++){
      	cin >> t;
        if(!act.size() || *act.begin()>=t)act.insert(t);
      	else{
        	auto p = act.lower_bound(t); p --;
          	act.erase(p);
          	act.insert(t);
        }
   	}
  	cout << act.size() << endl;
}