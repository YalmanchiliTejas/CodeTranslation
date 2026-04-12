#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
int INF = 1LL << 30;
int MOD = 1e9+7;
main(){
    int N;
    cin >> N;
    vector<int> A(N),B(N);
    for(int i = 0;i < N;i++){
        scanf("%d",&A[i]);
        B[i] = A[i];
    }
    sort(A.begin(),A.end());
    int l = A[N/2-1],r = A[N/2];
    for(int i = 0;i < N;i++){
        printf("%d\n",B[i] > l ? l : r);
    }
}