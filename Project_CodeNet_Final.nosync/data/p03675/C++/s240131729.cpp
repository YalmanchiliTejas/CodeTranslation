#include <iostream>
#include <deque>

# define REP(i,n) for(int i=0; i<n;i++)

using namespace std;

int main(){
	
	long long int n;
	long long int a[200005];
	cin >> n;
	REP(i,n){
		cin >> a[i];
	}
	
	
	deque<long long int> b;
	
	if(n%2==0){
		REP(k,n/2){
			b.push_front(a[2*k]);
			b.push_back(a[2*k+1]);
		}
	}else{
//		cout << (a[0]);
		b.push_front(a[0]);
		REP(k,(n-1)/2){
			b.push_front(a[2*k+1]);
			b.push_back(a[2*k+2]);
		}
//		b.pop_back();
	}
	
	cout << b.back();
	b.pop_back();
	
	REP(i,n-1){
//		cout << "po" << endl;
		cout <<" " << b.back();
		b.pop_back();
	}
	cout << endl;
	return 0;
	
}
