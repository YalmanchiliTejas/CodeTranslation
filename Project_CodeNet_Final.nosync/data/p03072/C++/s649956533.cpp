#include <bits/stdc++.h>

using namespace std; 

int main(){
	
	int N ; 
	
	vector<int> M(25);
	
	cin >> N; 
	
	for(int i=0; i<N;i++)  cin >> M[i];
	
	int ans = 1;
	int max = M[0];
	
	for(int i = 1 ; i< N ; i++ ){
		if(M[i] >= max){
			ans++;
			max = M[i];
		}
	}
	
	cout << ans << endl;
	
	
    return 0;
}
