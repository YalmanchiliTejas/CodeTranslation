#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    int s[100000];
    for(int i=0;i<n;i++) cin >> s[i];

    static vector<int64_t> lsum[100000], rsum[100000];
    for(int j=1;j<n;j++){
        lsum[j].push_back(0);
        rsum[j].push_back(0);
        for(int k=0;k<n;k+=j) lsum[j].push_back(lsum[j].back()+s[k]);
        for(int k=n-1;k>=0;k-=j) rsum[j].push_back(rsum[j].back()+s[k]);
    }

    int64_t ans = 0;
    for(int a=2;a<=n-2;a++){
        int r = n-1-a;
        for(int j=1;j*j<=r;j++){
            if(r%j != 0) continue;
            if(a%j != 0 || a/j > r/j){
                if(a-j > 0){
                    //A-B = j
                    int64_t cur = lsum[j][r/j+1] + rsum[j][r/j+1];
                    ans = max(ans, cur);
                }
            }
            if(a%(r/j) != 0 || a/(r/j) > j){
                //A-B = r/j
                if(a-r/j > 0){
                    int64_t cur = lsum[r/j][j+1] + rsum[r/j][j+1];
                    ans = max(ans, cur);
                }
            }
        }
    }

    cout << ans << endl;
    
    return 0;
}