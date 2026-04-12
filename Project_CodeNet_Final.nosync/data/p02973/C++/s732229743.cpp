#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MOD 1000000007
#define INF 1e9
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define all(x) (x).begin(),(x).end()
template<typename T> using min_priority_queue = priority_queue<T, vector<T>, greater<T>>;

int main(){
	int n;
	cin>>n;
	vector<int> a(n);
	rep(i,n) cin>>a[i];
	deque<int> d;
 	rep(i,n){
		 int p=lower_bound(all(d),a[i])-d.begin();
		 if(p==0){
			 d.push_front(a[i]);
		 }
		 else d[p-1]=a[i];
	 }
	 cout<<d.size()<<endl;

}