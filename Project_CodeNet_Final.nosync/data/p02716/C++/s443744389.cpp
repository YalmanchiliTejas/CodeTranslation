#include<bits/stdc++.h>
using namespace std;
typedef long long INT;

INT A[200100], n, C[200100][3];

INT f(INT i, INT c){
    if(C[i][c]) return C[i][c];
    INT k;
    if(i+c==n) return A[i];
    if(i>n) return 0;
    k = f(i+2, c) + A[i];
    if(c>0) k = max(k,f(i+3, c-1) + A[i]);
    if(c>1) k = max(k,f(i+4, c-2) + A[i]);

    return C[i][c]=k;
}
int main(){
    INT i;
    cin >>n;
    for(i=1;i<=n;i++) cin >> A[i];
    if(n%2==0) cout << max(f(1, 1),f(2,0));
    else cout <<max(f(1, 2),max(f(2,1),f(3,0)));
}
