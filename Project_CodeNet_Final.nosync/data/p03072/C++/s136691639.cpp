#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <climits>
#include <cassert>
#include <iostream>
#include <string>
#include <stack>
#include <queue>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <numeric>
#include <sstream>
#include <bitset>

using namespace std;
typedef long long ll;

int main() {
    std::ios::sync_with_stdio(0); cin.tie(0);


    ll ans=0;
    ll anss =0;
    ll count=0;
    ll i,j;
  
    ll k;
    vector<ll> d;

    ll Q,N;
    string S;
    cin>>N;
    ll aa[N];
    ans=N;
    for(i=0;i<N;i++){
        cin>>aa[i];
        for(j=0;j<i;j++){
            if(aa[i]<aa[j]){
                ans=ans-1;
                break;
            }
        }
    }
    

        cout<< ans << endl;

 
}