#include<iomanip>
#include<limits>
#include<thread>
#include<utility>
#include<iostream>
#include<string>
#include<algorithm>
#include<set>
#include<map>
#include<vector>
#include<stack>
#include<queue>
#include<cmath>
#include<math.h>
#include<numeric>
#include<cassert>
#include<random>
#include<deque>
#include<chrono>
#include<unordered_map>
#include<list>
#include<fstream>
using namespace std;
typedef unsigned long long int ull;
typedef long long int ll;
typedef pair<ll,ll> pll;
typedef pair<int,int> pi;
typedef pair<double,double> pd;
const ll E=1e18+7;
#define F first
#define S second
#define MK make_pair
const ll MOD=1000000007;





int main(){
    ll n;
    cin>>n;
    vector<ll> a(n);
    vector<ll> b(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
        b[i]=a[i];
    }
    sort(a.begin(),a.end());
    for(int i=0;i<n;i++){
        if(b[i]>=a[n/2]){cout<<a[n/2-1]<<endl;}
        else{cout<<a[n/2]<<endl;}
    }
    
    
    
    return 0;
}
