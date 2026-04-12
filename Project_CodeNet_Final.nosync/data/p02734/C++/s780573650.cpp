#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <string>
#include <cmath>
#include <iostream>
#include <set>
#include <stack>
#include <queue>
#include <numeric>
#include <deque>
#include <cstring>
#include <iterator>
#include <map>
#include <cstdlib>
#include <unordered_map>
#include <unordered_set>
#include <iomanip>
#include <complex>
#include <bitset>
#include <chrono>

using namespace std;
const int mod=998244353;





int main()
{   ios_base::sync_with_stdio(false);cin.tie(NULL);
    long long int n,m,k,q,d,x,l,a,b,c;
    cin>>n>>m;
    vector<long long int > v(n+1);
    vector<vector<long long int> > vec(n+1,vector<long long int>(m+1));
    vec[0][0]=1;
    for (int i=1; i<=n; i++) {
        cin>>v[i];
    }
    long long int ans =0;
    for (int i=1; i<=n; i++) {
        vec[i]=vec[i-1];
        vec[i][0]++;
        for (int j=v[i]; j<=m; j++) {
            vec[i][j]+=vec[i-1][j-v[i]];
            vec[i][j]%=mod;
        }
        ans+=vec[i][m];
        ans%=mod;
    }
    cout<<ans<<"\n";
    
    return 0;
}
