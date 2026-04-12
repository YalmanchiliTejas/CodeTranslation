#include <bits/stdc++.h>
using namespace std;

int main(){
	int N,c = 1;
	cin >> N;
	vector<int> H(N);
	for(int i = 0;i <N;i++){
	    cin >> H.at(i);
    }
	bool flag;
    for(int i = 1;i < N;i++){
    	flag = false;
	    for(int j = 0;j<i;j++){
	        if(H.at(i)<H.at(j)){
	            flag = true;
	        }
	    }
	    if(flag == true){
	    	continue;
	    }
	    c += 1;
	}
    cout << c;
}