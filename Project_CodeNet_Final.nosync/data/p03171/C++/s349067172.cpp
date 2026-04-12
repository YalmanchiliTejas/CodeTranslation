#include<bits/stdc++.h>
#define N 3005

using namespace std;

long long cost[N][N];
long long a[N];

long long solve(int l, int r){
    if(cost[l][r] != -1)
        return cost[l][r];
    if(l == r)
        return cost[l][r] = a[l];
    return cost[l][r] = max(a[l] - solve(l + 1, r), a[r] - solve(l, r - 1));
}

int main(){
    int n;
    cin>>n;
    for(int i = 1 ; i <= n ; i++)
        cin>>a[i];
    memset(cost, -1, sizeof cost);

    cout<<solve(1, n);
    return 0;
}
