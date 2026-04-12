#include <bits/stdc++.h>

#define mod 1000000007

#define rep(i, n) for(int i=0; i<n; ++i)

using namespace std;
typedef long long ll;
const long long INF = 1LL << 60;
 
int main(void){
	
	string S;
    cin >> S;

    if(S[0] == 'A' && S[1] == 'A' && S[2] == 'A')
        cout << "No" << endl;
    else if(S[0] == 'B' && S[1] == 'B' && S[2] == 'B')
        cout << "No" << endl;
    else
        cout << "Yes" << endl;
	
	return 0;
}