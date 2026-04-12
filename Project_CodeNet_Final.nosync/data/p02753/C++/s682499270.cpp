#include <bits/stdc++.h>
using namespace std;

int main() {
    int N=3;
    string S;
    cin >> S;
    //AAB Y
    //BBA Y
    //BBB
    string result;
    for(int i=0;i<N-1;i++){
		if(S[i+1]!=S[i]){
			cout<<"Yes"<<endl;
			return 0;
		}
    }
	result="No";
    cout << result << endl;

    return 0;
}
