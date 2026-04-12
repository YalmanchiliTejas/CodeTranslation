#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for (int i=0;i<(n);i++)
//#define int long long  
#define INF 1145141919810893

int main(){
    long long int K,A,B;
    cin >> K >> A >> B;
    if(K<=A){cout << 1 << endl;return 0;}
    if(A<=B){cout << -1 << endl;return 0;}
    K-=A;
    cout << 3+((long long int)(K-1)/(A-B))*2  << endl;
    return 0;
}