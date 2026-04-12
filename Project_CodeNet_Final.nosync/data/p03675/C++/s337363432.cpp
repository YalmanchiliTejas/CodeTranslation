#include<bits/stdc++.h>
using namespace std;

#define all(x) (x).begin(), (x).end()
#define rall(x) (x).begin(),(x).rend()

typedef vector<int> vi;
typedef long long ll;
typedef pair<int,int> PII;
typedef pair<long long,long long> PLL;

const int mod=1e+9+7;


int main(){
	int n;
	cin>>n;

	deque<int> deq;
	if(n%2==0){
		for (int i = 0; i < n; ++i){
			int a;
			cin>>a;
			if(i%2==0){
				deq.push_back(a);
			}else{
				deq.push_front(a);
			}
		}
	}else{
		for (int i = 0; i < n; ++i){
			int a;
			cin>>a;
			if(i%2==0){
				deq.push_front(a);
			}else{
				deq.push_back(a);
			}
		}
	}

	while(deq.size()){
		cout<<deq.front()<<" ";
		deq.pop_front();
	}

	cout<<endl;


	return 0;
}