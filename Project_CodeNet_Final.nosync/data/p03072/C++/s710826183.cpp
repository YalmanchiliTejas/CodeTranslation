#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<map>
#include<set>
#include<queue>
#include<stack>
#include<limits>
#include<iomanip>
#include<cmath>
#include<climits>

using namespace std;

typedef long long ll;
typedef pair<int,int> P;

const int mod=1e9+7;

int main(){
    int n;
    cin >> n;
    vector<int> h(n);
    for(int i=0;i<n;i++)    cin >> h[i];
    int ans=0;
    for(int i=0;i<n;i++){
        bool ok=true;
        for(int j=0;j<=i;j++){
            if(h[j]>h[i])   ok=false;
        }
        if(ok)  ans++;
    }
    cout << ans << endl;
    return 0;
}
