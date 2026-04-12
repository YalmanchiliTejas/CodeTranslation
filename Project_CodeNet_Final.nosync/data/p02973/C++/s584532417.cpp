#include<iostream>
#include<iomanip>
#include<cmath>
#include<string>
#include<vector>
#include<list>
#include<algorithm>
#include<map>
#include<set>
#include<queue>
#include<stack>
using namespace std;
typedef long long ll;
#define fi first
#define se second
#define mp make_pair
const int inf=1e9+7;
const ll mod=1e9+7;
const ll big=1e18;

vector<int> DP(100005);

int main() {
    int N;
    cin>>N;
    for(int i=0;i<100005;++i){
        DP[i] = inf;
    }
    vector<int> arr(N);
    for(int i=0;i<N;++i){
        cin>>arr[i];
    }
    reverse(arr.begin(), arr.end());
    int index;
    for(int i=0;i<N;++i){
        index = upper_bound(DP.begin(), DP.end(), arr[i]) - DP.begin();
        DP[index] = arr[i];
    }
    cout<<lower_bound(DP.begin(), DP.end(), inf) - DP.begin()<<endl;
}

