#include <iostream>
#include <algorithm>

using namespace std;

int N;
int A[200005], a[200005];;

int main(void)
{
	cin >> N;
	for(int i = 1; i <= N; i++) cin >> A[i];
	for(int i = 1; i <= N; i++){
		a[i] = A[i];
	}
	sort(a+1, a+N+1);
	
	int l = a[N/2], r = a[N/2+1];
	if(l == r){
		for(int i = 1; i <= N; i++){
			cout << l << endl;
		}
		return 0;
	}
	
	for(int i = 1; i <= N; i++){
		if(A[i] <= l) cout << r << endl;
		else cout << l << endl;
	}
	return 0;
}