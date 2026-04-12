#include<bits/stdc++.h>
using namespace std;
#define ALL(x) x.begin(),x.end()
#define rep(i,n) for(int i=0;i<n;i++)
#define INF 1000000000
#define mod 1000000007
typedef long long ll;
const ll LINF = 1001002003004005006ll;
int dx[]={1,0,-1,0};
int dy[]={0,1,0,-1};
int gcd(int a,int b){return b?gcd(b,a%b):a;}

int main(){
    int r,g,b;
    cin>>r>>g>>b;
    cout<<(((r*100+g*10+b)%4)?"NO":"YES")<<endl;
    return 0;
}
