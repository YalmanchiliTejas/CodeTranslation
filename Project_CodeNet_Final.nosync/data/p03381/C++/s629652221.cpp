#include <bits/stdc++.h>

using namespace std;

template<typename T> std::ostream& operator<<(std::ostream&o, const std::vector<T>&t) {
	// this way helps deal with empty vector
	for (size_t i = 0; i < t.size(); ++i) {
		o << t[i] << " \n"[i == t.size() - 1];
	}
	return o;
}

int N;
vector<int> a;
void solve(){
	cin>>N;

	a.reserve(N);
	for (int i=0;i<N;i++){
		int x;
		cin>>x;
		a.push_back(x);
	}
	vector<int> b(a);
	nth_element(a.begin(), a.begin()+(N-1)/2, a.end());
	int m1 = a[(N-1)/2];
	int m2 = *min_element(a.begin()+(N+1)/2, a.end());
//	cout<<m1<<','<<m2<<endl;
	for (int i=0;i<N;i++){
		if (b[i]<=m1){
			cout<<m2<<'\n';
		}
		else{
			cout<<m1<<'\n';
		}
	}
}

int main(){
// 	freopen("in.txt","r",stdin);
// 	freopen("out.txt","w",stdout);
	std::ios::sync_with_stdio(false);

		solve();

	return 0;
}

