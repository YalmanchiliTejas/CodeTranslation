#include<iostream>
#include<set>
using namespace std;

int main(){
	int N;
	cin >> N;
	multiset<int> seta;
	int res = 0;
	for(int i = 0; i < N; i++){
		int A;
		cin >> A;
		if(seta.empty()){
			seta.insert(A);
			res++;
		}else{
			multiset<int>::iterator itr = seta.lower_bound(A);
			if(itr == seta.begin()){
				seta.insert(A);
				res++;
			}else{
				itr--;
				seta.erase(itr);
				seta.insert(A);
			}
		}
	}
	cout << res << endl;
	return 0;
}