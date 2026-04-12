#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <iomanip>
#include <queue>
#include <deque>
#include <map>
#include <unordered_map>
#define rep(i,n) for(int i=0;i<n;i++)
#define repn(i,n) for(int i=1;i<=n;i++)
#define repr(e,x) for(auto& e:x)
using namespace std;
typedef long long ll;
typedef long double ld;
//typedef pair<int,int> P;
int const INF=1001001001;
ll const LINF=1001001001001001001;
ll const MOD=1000000007;

int N;
int A[100000];

int main(){
    cin>>N;
    rep(i,N) cin>>A[i];

    vector<int> v;
    rep(i,N){
        if(v.empty()){
            v.push_back(A[i]);
            continue;
        }
        int l=-1, r=v.size();
        while(r-l>1){
            int mid=(l+r)/2;
            if(v[mid]<A[i]) r=mid;
            else l=mid;
        }
        if(r==v.size()) v.push_back(A[i]);
        else v[r]=A[i];
    }

    int ans=v.size();
    cout<<ans<<endl;
}