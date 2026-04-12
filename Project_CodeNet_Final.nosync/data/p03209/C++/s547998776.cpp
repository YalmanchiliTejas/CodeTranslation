#include <bits/stdc++.h>
using namespace std;

vector<long long int> a(51), p(51);

long long int rec(long long int n, long long int x){
    // terminal case
    if(n == 0){
        if(x <= 0) return 0;
        else return 1;
    }

    else if(x <= 1 + a[n-1]) return rec(n-1,x-1);
    else return p[n-1] + 1 + rec(n-1,x-a[n-1]-2);
}

int main(){
    long long int n, x;
    cin >> n >> x;

    a[0] = 1;
    p[0] = 1;
    for(int i=1; i<n+1; i++){
        a[i] = 2 * a[i-1] + 3;
        p[i] = 2 * p[i-1] + 1;
    }

    cout << rec(n, x) << endl;
    return 0;
}