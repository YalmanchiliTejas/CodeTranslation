#include<iostream>
#include<vector>

using namespace std;

int main(){
	int N,ans(0),M(0);
  	cin >> N;
  	vector<int> h(N);
  	for(int i = 0 ; i < N ; i ++){
      	cin >> h[i];
      	if(h[i] >= M){
        	M = h[i];
          	ans ++;
        }
    }
  	cout << ans << endl;
}