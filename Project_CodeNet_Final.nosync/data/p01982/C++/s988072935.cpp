#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define f(i,x,n) for(int i=x;i<(int)(n);++i)
#define all(x) (x).begin(),(x).end()
const int mod=1000000007,MAX=200005,INF=1<<30;

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    while(1){
        int N,L,R;cin>>N>>L>>R;
        if(N+L+R==0) break;
        
        vector<int> A(N);
        for(int i=0;i<N;i++) cin>>A[i];
        int ans=0;
        
        for(int i=L;i<=R;i++){
            for(int j=0;j<N;j++){
                if(i%A[j]==0){
                    if(j%2==0) ans++;
                    break;
                }
                if(j==N-1&&N%2==0) ans++;
            }
        }
        
        cout<<ans<<endl;
    }
}

