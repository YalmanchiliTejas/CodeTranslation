#include <bits/stdc++.h>

#define mod 1000000007

using namespace std;
typedef long long ll; 
 
int main(void){
	
	int N, count, ans = 1;
	
	cin >> N;
	
	int H[N];
	
	for(int i=0; i<N; i++)
		cin >> H[i];
	
	for(int i=1; i<N; i++){
		count = 0;
		for(int j=0; j<i; j++){
			if(H[i] >= H[j])
				count++;
		}
		if(count == i)
			ans++;
	}
	
	cout << ans;
	
	return 0;
}