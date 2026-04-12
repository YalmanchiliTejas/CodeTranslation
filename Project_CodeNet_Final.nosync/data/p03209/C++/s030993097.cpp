#include <bits/stdc++.h>
using namespace std;

#define int long long
const double PI = 3.14159265358979323846;
typedef vector<int> vint;
typedef pair<int, int> pint;
const int dx[8] = {1, 0, -1, 0, 1, -1, -1, 1};
const int dy[8] = {0, 1, 0, -1, 1, 1, -1, -1};
// cout << fixed << setprecision(20);

int N,X;
int h[55],p[55];
int f(int n,int x){
    if(n==0)return x;
    if(x<=1)return 0;
    if(x>=h[n]-1)return p[n];
    if(x>=h[n-1]+2) return p[n-1]+f(n-1,x-h[n-1]-2)+1;
    return f(n-1,x-1);
}
signed main() {
    cin>>N>>X;
    h[0]=1;
    for(int i=1;i<55;i++)h[i]=h[i-1]*2+3;
    p[0]=1;
    for(int i=1;i<55;i++)p[i]=p[i-1]*2+1;
    cout<<f(N,X)<<endl;

}
