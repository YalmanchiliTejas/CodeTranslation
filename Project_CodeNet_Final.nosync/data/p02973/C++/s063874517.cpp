#include<cstdio>
#include<cstring>
#include<cmath>
#include<cassert>
#include<iostream>
#include<iomanip>
#include<map>
#include<set>
#include<vector>
#include<algorithm>
#include<string>
#include<queue>
using namespace std;
#define DEBUG(x) cout<<#x<<"="<<x<<endl
#define DEBUG2(x,y) cout<<#x<<"="<<x<<","<<#y<<"="<<y<<endl
typedef long long ll;
class Solver{
public:
    void solve(){
        ios::sync_with_stdio(false);
        cin.tie(0);
        int n;
        cin>>n;
        multiset<int>m;
        for(int u=0;u<n;u++){
            int a;
            cin>>a;
            auto it=m.lower_bound(a);
            if(it!=m.begin()){
                it--;
                m.erase(it);
            }
            m.insert(a);
        }
        cout<<m.size();
    }
};
int main()
{
    // freopen("in.txt","r",stdin);
    (new Solver())->solve();
}