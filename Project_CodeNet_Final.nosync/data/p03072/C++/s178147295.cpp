#include <bits/stdc++.h>
using namespace std;
int main(){
	int N,ans;
	cin >> N;
	vector<int> data (N,0);
  	for(int i=0;i<N;i++){
    	cin >> data.at(i);
    }
  	for(int j=0;j<N;j++){
      	bool flag=1;
    	for(int k=0;k<j;k++){
        if(data.at(k)>data.at(j)) flag=0;
        }
    if(flag) ans++;
    }
    cout << ans << endl;
}