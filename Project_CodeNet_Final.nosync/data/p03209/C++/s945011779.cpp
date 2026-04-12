#include<bits/stdc++.h>
using namespace std;

#define rep(i,a,b) for(int i=(a);i<(b);i++)
#define repr(i,a,b) for(int i=(a); i>=(b); i--)
#define all(x) (x).begin(),(x).end()
typedef long long ll;
typedef pair<int,int> P;
const int INF=1<<29;

ll N,X;

ll solve(int N,ll X){
    if(X==0)return 0;
    if(N==0)return 1;
    
    if(X>=(1LL<<(N+1))-1){
        return (1LL<<N) + solve(N-1,X+1-(1LL<<(N+1)));
    }
    return solve(N-1,X-1);
}

int main(){
    
    cin>>N>>X;
    
    cout<<solve(N,X)<<endl;
    
    return 0;
}