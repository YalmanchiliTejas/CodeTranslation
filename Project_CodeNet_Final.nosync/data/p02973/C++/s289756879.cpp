#include <bits/stdc++.h>

using namespace std;

#define debug(x) cout << "\n" << __LINE__ << " " <<  (#x) << " is " << (x) << endl

int main(){
	#ifdef EVAL	
		freopen("input.txt","r",stdin);
		//freopen("output.txt","w",stdout);
	#endif
	int N;
	cin >> N;
	multiset <int> S;
	S.insert(-1);
	S.insert(INT_MAX);
	for(int i = 0, x; i < N; i++){
		cin >> x;
		multiset<int>::iterator it = S.lower_bound(x);
		it--;
		if((*it) == -1){
			S.insert(x);
		}else{
			S.erase(it);
			S.insert(x);
		}
	}
	cout << S.size() - 2;
	return 0;
}