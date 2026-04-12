#include<iostream>
#include<vector>
using namespace std;
int main(){
	int N;cin>>N;
	vector<int>H(N);
	for(int i=0;i<N;i++){
		cin>>H[i];
	}
	
	int ans=1;
  	int max=H[0];
	for(int i=1;i<N;i++){
      	if(min(max,H[i])==max){
          	max = H[i];
			ans += 1;
        }
	}
	
	cout << ans << endl;
}