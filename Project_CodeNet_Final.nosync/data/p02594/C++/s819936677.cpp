#include <bits/stdc++.h>
const double PI=acos(-1);
using namespace std;
#define ll long long
#define ull unsigned long long
#define ul unsigned long
#define MOD 1000000007

long findmin(long a,long b) {
    return a<b?a:b;
}
long findmax(long a,long b) {
    return a>b?a:b;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int x;
    cin>>x;
    if(x>=30) {
		cout<<"Yes\n";
	}
	else {
		cout<<"No\n";
	}
    cout.flush();
	return 0;
}
