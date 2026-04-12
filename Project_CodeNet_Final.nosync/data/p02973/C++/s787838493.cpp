#include<bits/stdc++.h>
using namespace std ;
#define ll long long int 
#define pb push_back 
#define mp make_pair 
#define pii pair <int , int > 
#define pll pair < ll , ll >
int main(){
	ios_base::sync_with_stdio(false) ;
	cin.tie(NULL) ;
	int n ;
	cin >> n ;
	int arr[n] ;
	for(int i = 0 ; i < n ; i++) cin >> arr[i] ;
	multiset < int > m ;
	m.insert(arr[0]) ;
	// cout << *m.begin() ;
	for(int i = 1 ; i < n ; i++){
		if(arr[i] > *m.begin()){
			auto it = m.lower_bound(arr[i]) ;
			it-- ;
			m.erase(it) ;
			m.insert(arr[i]) ;
		}
		else m.insert(arr[i]) ;
	}
	cout << m.size() ;
}