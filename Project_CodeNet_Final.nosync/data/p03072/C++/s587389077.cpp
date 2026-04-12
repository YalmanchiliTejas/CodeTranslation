#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
#include <map>
#include <vector>
#include <stack>
#include <queue>
#include <tuple>

using namespace std;
typedef long long ll;
int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};
const int INF = 1<<29;

int main(){
    int N; cin >> N;
    vector<int> H(N);
    for(int i=0;i<N;i++){
        cin >> H[i];
    }
    int ans=1;
    for(int i=1;i<N;i++){
        bool f=true;
        for(int j=0;j<i;j++){
            if(H[j]>H[i]){
                f=false;
            }
        }
        if(f) ans++;
    }
    cout << ans << endl;
    return 0;
}
