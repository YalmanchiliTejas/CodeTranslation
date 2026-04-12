#include<iostream>
#include<string>
#include<algorithm>
#include<cmath>
#include<iomanip>
#include<cstring>
#include<map>
#include<vector>
#include<queue>
#include<climits>
#include<set>
#include<utility>
using namespace std;
typedef long long int ll;
const ll MOD=1e9+7;

int main(){

	int n, a[200000], b[200000];
	cin >> n;
	for(int i=0; i<n; i++){
		cin >> a[i];
	}
	int s=n/2;
	for(int i=0; i<n; i++){
		s+=i*pow(-1, i);
		b[s]=a[i];
	}
	if(n%2==0){
		for(int i=0; i<n; i++){
			cout << b[i] <<" ";
		}
	} else {
		for(int i=n-1; 0<=i; i--){
			cout << b[i] <<" ";			
		}
	}
	cout << endl;

	return 0;
}
