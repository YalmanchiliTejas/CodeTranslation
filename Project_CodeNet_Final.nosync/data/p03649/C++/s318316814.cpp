#include <iostream>
#include <vector>

using namespace std;

int main(){
	int N;
	while(cin >> N){
		vector<long long> a(N);
		for(auto& t : a) cin >> t;
		long long res = 0;
		while(true){
			bool update = false;
			for(int i=0;i<N;i++){
				if(a[i] <= N-1) continue;
				long long dec = a[i]/N;
				a[i] -= N * dec;
				for(int j=0;j<N;j++) if(i != j) a[j] += dec;
				res += dec;
				update = true;
			}
			if(!update) break;
		}
		cout << res << endl;
	}
}
