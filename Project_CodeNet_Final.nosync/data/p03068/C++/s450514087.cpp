#include<iostream>
#include<string>
#include <vector>
using namespace std;

typedef  long long ll;

int main(){
	
	int N;
  	string S;
  	int K;
  	cin >> N;
  	cin >> S;
  	cin >> K;
	//cout <<S[K-1]<<endl;
  	for(int i = 0; i < N ; i++){
    	if(S[i]==S[K-1]){

	    cout << S[K-1];
    	}else{
        cout << "*";
        }
    }
  	

    	cout  << endl;





  	
  
}