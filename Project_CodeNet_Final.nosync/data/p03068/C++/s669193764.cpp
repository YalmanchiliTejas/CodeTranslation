#include <iostream>
using namespace std;


int main() {
    int N,K;
	string S;
    cin >> N >> S >> K ;
	char temp=S[K-1];
	
    
for(int i=0;i<S.length();i++){
if(S[i]==temp)
    cout << S[i];
else
    cout << "*";


}
return 0;
}