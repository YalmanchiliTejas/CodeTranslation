#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);i++)
#define N 100000
typedef long long ll;
#define ALL(v) (v).begin(),(v).end()
#define SZ(x) int(x.size())
#define OUT(a) cout<<(a)<<endl
#define VECIN(type, c, n) vector<type> c(n);for(auto& i:c) cin>>i;


int main(){
	int n;
    cin>>n;
    vector<int> a(n);
    REP(i,n){
      cin>>a[i];
    }
    vector<int> b;
    b.push_back(a[n-1]);
    for(int i=n-2;i>=0;i--){
        if(a[i]>=b[SZ(b)-1]){
            b.push_back(a[i]);
        }else{
            auto x=upper_bound(ALL(b),a[i]);
            b[x-b.begin()]=a[i];
        }
    }
    OUT(SZ(b));
	return 0;
}