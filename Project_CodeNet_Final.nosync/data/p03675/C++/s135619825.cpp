#include<iostream>
#include<string>
#include<typeinfo>
#include<vector>
#include<algorithm>
#include<map>
#include<iomanip>
typedef long long int ll;
using namespace std;
int main()
{
	int n;
	cin >> n;
	vector<ll> a(n);
	for(int i=0; i<n; i++){
		cin >> a.at(i);
	}

	if(n%2==0){
		for(int i=n-1; i>=0; i-=2){
			cout << a.at(i) << " ";
		}
		for(int i=0; i<=n-1; i+=2){
			cout << a.at(i) << " ";
		}
	}else{
		for(int i=n-1; i>=0; i-=2){
			cout << a.at(i)<< " ";
		}
		for(int i=1; i<=n-2; i+=2){
			cout << a.at(i) << " ";
		}
	}
	cout << endl;
	return 0;
}
