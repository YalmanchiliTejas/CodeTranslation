#include<bits/stdc++.h>
using namespace std;

#define mp make_pair
#define pb push_back
#define st first
#define nd second

typedef long long ll;
typedef pair < ll , ll > pp;
const int mod = 1e9 + 7;
const int N   = 2e5 + 5;

int A[N],B[N],n,i;

main(){
    cin >> n;
    for(i=1;i<=n;i++) { cin >> A[i]; B[i] = A[i]; }
    sort(B+1 , B+n+1);

    for(i=1;i<=n;i++){
        if(A[i] < B[n/2+1]) cout << B[n/2+1];
        else cout << B[n/2];
        cout << endl;
    }
    return 0;
}