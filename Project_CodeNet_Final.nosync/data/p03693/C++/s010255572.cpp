#include<bits/stdc++.h>
using namespace std; 
typedef long long ll;

int main(){
    int c[3];
    cin >> c[0] >> c[1] >> c[2];
    int res = 100 * c[0] + 10 * c[1] + 1 * c[2];

    if (res % 4 == 0){
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
 
	return 0;
}