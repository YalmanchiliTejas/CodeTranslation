#include <bits/stdc++.h>
using namespace std;
#define MD 1000000007
typedef long long int ll;
typedef pair<ll, ll> P;
template <typename T>
std::string tostr(const T &t){std::ostringstream os;os << t;return os.str();}
int dx[4]={1, 0, -1, 0}, dy[4]={0, 1, 0, -1};

int main()
{
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    int ans=1;
    for(int i=n-1;i>=1;i--){
        int cnt=0;
        for(int j=i-1;j>=0;j--){
            if(v[i]>=v[j]){
                cnt++;
            }
        }
        if(cnt==i){
            ans++;
        }
    }
    cout<<ans<<endl;
    return 0;
}