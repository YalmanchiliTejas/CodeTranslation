#include<bits/stdc++.h>
using namespace std;
#define fs first
#define sc second
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define ALL(A) A.begin(),A.end()
#define RALL(A) A.rbegin(),A.rend()
typedef long long LL;
typedef pair<LL,LL> P;
const LL mod=1e9+7;
const LL LINF=1LL<<62;




int main(){
    int N;cin >> N;
    int h,m=0,ans=0;
    for (int i = 0; i < N; i++) {
        cin >> h;
        if(h>=m){
            ans++;
            m=h;
        }
    }
    cout << ans << endl;
    return 0;
}

