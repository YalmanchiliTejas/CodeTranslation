#include <bits/stdc++.h>

using namespace std;

#define int long long
const double PI = 3.14159265358979323846;
typedef vector<int> vint;
typedef pair<int, int> pint;
const int dx[8] = {1, 0, -1, 0, 1, -1, -1, 1};
const int dy[8] = {0, 1, 0, -1, 1, 1, -1, -1};
// cout << fixed << setprecision(20);

int N;
int A[110000];
multiset<int> aset;
signed main() {
    cin>>N;
    int ans=0;
    for(int i=0;i<N;i++){
        cin>>A[i];
        A[i]*=-1;
        auto it=aset.upper_bound(A[i]);
        if(it!=aset.end()){
            aset.erase(it);
            cerr<<i<<endl;
        }
        else ans++;
        aset.insert(A[i]);
        //cerr<<aset.size()<<endl;
    }
    cout<<ans<<endl;
}