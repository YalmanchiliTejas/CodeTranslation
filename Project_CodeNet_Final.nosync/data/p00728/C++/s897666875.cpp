#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const int mod=1000000007,MAX=1<<17,INF=1<<30;

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    while(1){
        int N;cin>>N;
        if(N==0) return 0;
        
        vector<int> A(N);
        for(int i=0;i<N;i++) cin>>A[i];
        sort(all(A));
        
        ll sum=0;
        
        for(int i=1;i<N-1;i++) sum+=A[i];
        cout<<sum/(N-2)<<endl;
    }
}

