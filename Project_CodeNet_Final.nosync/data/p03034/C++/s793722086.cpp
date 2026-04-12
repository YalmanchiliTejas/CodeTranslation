#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
#define all(x) (x).begin(),(x).end()
using namespace std;
const int INF=1145141919,MOD=1e9+7;
const int64_t LINF=8931145141919364364,LMOD=998244353;
// const int dx[]={1,0,-1,0,1,1,-1,-1},dy[]={0,-1,0,1,1,-1,-1,1};

int main(){
    int n; cin>>n;
    int64_t s[n]; rep(i,n) cin>>s[i];
    int64_t ans=0;
    for(int c=1;c<n;c++){
        int64_t sum=0;
        set<int> used;
        for(int k=0;k*c<n;k++){
            int a=(n-1)-k*c;
            if(a<=0) continue;
            int b=a-c;
            if(a<=b) continue;
            if(k>0 and b<=0) continue;
            if(used.find(k*c)!=used.end()) break;
            used.insert(k*c);
            sum+=s[k*c];
            if(used.find((n-1)-k*c)!=used.end()) break;
            used.insert((n-1)-k*c);
            sum+=s[(n-1)-k*c];
            ans=max(ans,sum);
        }
    }
    cout<<ans<<endl;
    return 0;
}

// 愚直
// for(int a=1;a<n;a++){
//     for(int b=1;b<a;b++){
//         // cerr<<a<<" "<<b<<endl;
//         int sum=0;
//         set<int> used; used.insert(0);
//         int now=0;
//         bool end=1;
//         while(1){
//             now+=a;
//             if(now>=n){
//                 end=0;
//                 break;
//             }
//             if(used.find(now)!=used.end()){
//                 end=0;
//                 break;
//             }
//             used.insert(now);
//             sum+=s[now];
//             if(now==n-1) break;
//             now-=b;
//             if(now<0){
//                 end=0;
//                 break;
//             }
//             if(used.find(now)!=used.end()){
//                 end=0;
//                 break;
//             }
//             used.insert(now);
//             sum+=s[now];
//         }
//         if(end) cerr<<a<<" "<<b<<" "<<sum<<endl;
//     }
// }
