//Only the Creator has given me strength!

#include<cstdio>

#include<sstream>

#include<cstdlib>

#include<cctype>

#include<cmath>

#include<algorithm>

#include<set>

#include<queue>

#include<stack>

#include<list>

#include<iostream>

#include<fstream>

#include<numeric>

#include<string>

#include<vector>

#include<cstring>

#include<map>

#include<iterator>

#include<bitset>

typedef long long ll;

#define pi 3.1415926535897931159979635

#define pb push_back

#define vctr vector < int >

#define vvtr vector < vctr >

using namespace std;

void fastio() {

    ios::sync_with_stdio(0);

    cin.tie(0);

    cout.tie(0);

}

int main() {

    fastio();

    ll mod=1e9+7,n;

    cin>>n;

    ll num[n],sum[n];

    for(int i=0; i<n; i++) {

        sum[i]=0;

        cin>>num[i];

        if(i!=0) sum[i]=sum[i-1]+num[i];

        else sum[i]=num[i];

    }

    ll ans=0;

    for(int i=0; i<n; i++) {

        ans=(ans+num[i]*((sum[n-1]-sum[i])%mod))%mod;

    }

    cout<<ans<<"\n";

    return 0;

}