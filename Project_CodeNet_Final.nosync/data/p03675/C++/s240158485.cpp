#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) repi(i,0,n)
#define repi(i,a,b) for(int i=(int)(a);i<(int)(b);i++)
typedef long long i64;
int main(){
    int N;
    cin >> N;
    int a[N];
    rep(i,N) cin >> a[i];
    int i=N-1,j=0;
    for(int i=N-1;i>(N%2==0 ? 0:-1);i-=2){
        cout << a[i];
        if(j!=N-1) cout <<  " ";
        else cout << endl;
    }
    for(int j=(N%2==0 ? 0:1);j<N-1;j+=2){
        cout << a[j];
        if(j!=N-2) cout <<  " ";
        else cout << endl;
    }
    return 0;
}
