#include <iostream>
#include <vector>
#include <algorithm>

#define REP(i, n) for(int i = 0; i < n; i++)

using namespace std;

int main(){
	int n,k;
    string s;
	cin>>n>>s>>k;
	
    char target = s[k-1];

	string result;
    REP(i,n){
        if( s[i] != target ){
            result += "*";
        }
        else{
            result += s[i];
        }
    }

    cout << result << endl;
	
	return 0;
}