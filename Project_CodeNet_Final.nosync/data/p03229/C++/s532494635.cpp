#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <climits>
#include <cfloat>
#include <map>
#include <utility>
#include <set>
#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <sstream>
#include <complex>
#include <stack>
#include <queue>
#include <iomanip>
#include <array>
#include <numeric>
#include <regex>
#include <bitset>
#include <deque>

using namespace std;
typedef long long ll;
typedef pair<int, int> p_ii;

const int INF = 1e9;
const double PI = acos(-1.0);
const ll MOD = 1e9 + 7;



int main() {
    int n;
    cin>>n;
    vector<int>a(n), b(n);
    for (int i = 0; i < n; i++) {
        cin>>a[i];
        b[i]=a[i];
    }
    sort(a.begin(),a.end());
    sort(b.begin(),b.end());

    ll sum = 0;
    int left=a[n-1], right=a[n-1];
    a[n-1]=-1;
    int midx=0, mxdx=n-2;
    for (int i = 0; i < n/2+1; i++) {
        if(i%2==1){
            if(a[mxdx]!=-1){
                sum+=(ll)abs(left-a[mxdx]);
                left=a[mxdx];
                a[mxdx]=-1;
            }
            if(mxdx-1>=0&&a[mxdx-1]!=-1){
                sum+=(ll)abs(right-a[mxdx-1]);
                right=a[mxdx-1];
                a[mxdx-1]=-1;
            }
            if(mxdx>=n/2&&mxdx-2>=0)mxdx-=2;
        }else{
            if(midx>=n/2)continue;
            if(a[midx]!=-1){
                sum+=(ll)abs(left-a[midx]);
                left=a[midx];
                a[midx]=-1;
            }
            if(midx+1<n&&a[midx+1]!=-1){
                sum+=(ll)abs(right-a[midx+1]);
                right=a[midx+1];
                a[midx+1]=-1;
            }
            if(midx<=n/2&&midx+2<n)midx+=2;
        }
    }

    ll sum2=0;
    left=b[0], right=b[0];
    b[0]=-1;
    midx=1;
    mxdx=n-1;

    for (int i = 0; i < n/2; i++) {
        if(i%2==0){
            if(b[mxdx]!=-1){
                sum2+=(ll)abs(left-b[mxdx]);
                left=b[mxdx];
                b[mxdx]=-1;
            }
            if(mxdx-1>=0&&b[mxdx-1]!=-1){
                sum2+=(ll)abs(right-b[mxdx-1]);
                right=b[mxdx-1];
                b[mxdx-1]=-1;
            }
            if(mxdx>=n/2&&mxdx-2>=0)mxdx-=2;
        }else{
            if(midx>=n/2)continue;
            if(b[midx]!=-1){
                sum2+=(ll)abs(left-b[midx]);
                left=b[midx];
                b[midx]=-1;
            }
            if(midx+1<n&&b[midx+1]!=-1){
                sum2+=(ll)abs(right-b[midx+1]);
                right=b[midx+1];
                b[midx+1]=-1;
            }
            if(midx<=n/2&&midx+2<n)midx+=2;
        }
    }


    cout<<max(sum,sum2)<<endl;

    return 0;
}