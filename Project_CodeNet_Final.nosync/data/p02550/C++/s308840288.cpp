//
//  main.cpp
//  AtCoderD
//
//  Created by Shivam on 19/09/20.
//  Copyright © 2020 Shivam. All rights reserved.
//

#include<iostream>
#include<vector>
#include<algorithm>
#include<utility>
#include<climits>
#include<cmath>
#include<cstring>
#include<unordered_set>
#include<unordered_map>
#include<set>
#include<stack>
#include<queue>
#include<map>
#include<list>
using namespace std;
//#define x first
//#define y second
#define mp make_pair
#define endl "\n"
typedef long long ll;
int mod=998244353;
ll next(ll a,ll m) {
    return (a*a)%m;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n,x,m;
    cin>>n>>x>>m;
    set<ll> s;
    ll sum=x;
    for(int i=1;i<n;++i) {
        x=next(x,m);
        if(x==0)
            break;
        else if(s.count(x)==0) {
            s.insert(x);
            sum+=x;
        }
        else {
            ll y=next(x,m);
            int len=1;
            ll msum=x;
            while(y!=x){
                msum+=y;
                y=next(y,m);
                len++;
            }
            ll quo,rem;
            quo=(n-i)/len;
            rem=(n-i)%len;
            sum+=msum*quo;
            while(rem--) {
                sum+=x;
                x=next(x,m);
            }
            break;
        }
        //cout<<sum<<endl;
    }
    cout<<sum<<endl;
    return 0;
}
