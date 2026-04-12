#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;


int n;
int A[200005];
int B[200005];
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin>>n;
    for(int i=0;i<n;i++) cin>>A[i];
    int p=0;
    for(int i=n-1;i>=0;i-=2) B[p++] = A[i];
    for(int i=(n)%2;i<n;i+=2) B[p++] = A[i];
    for(int i=0;i<n;i++) cout<<B[i]<<' ';
    return 0;
}
