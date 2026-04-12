#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i,n) for(int (i) = 0; (i) < (n); (i)++)


int main(){
	int n = 0;
	rep(i,3){
        int tmp;
        cin >> tmp;
        n *= 10;
        n += tmp;
	}
	cout << (n%4 ? "NO\n" : "YES\n");
}
