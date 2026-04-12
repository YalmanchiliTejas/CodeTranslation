#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <numeric>
#include <queue>
#include <deque>
#include <cmath>
#include <iomanip>
#include <cstdio>
#include <climits>

using namespace std;

int main(){
    int n;
    string s;
    cin >> n >> s;
    vector<bool> ans(n);
    bool found=false;
    for(int i=0; i<4; ++i){
        ans[0]=bool(i & 0x1);
        ans[1]=bool(i & 0x2);
        for(int j=1; j<n-1; ++j){
            if(ans[j] && s[j]=='o') ans[j+1]=ans[j-1];
            else if(ans[j] && s[j]=='x') ans[j+1]=!ans[j-1];
            else if(!ans[j] && s[j]=='o') ans[j+1]=!ans[j-1];
            else if(!ans[j] && s[j]=='x') ans[j+1]=ans[j-1];
        }
        found=true;
        for(int j=-1; j<1; ++j){
            int jl=(j+n-1)%n, ji=(j+n)%n, jr=j+1;
            if(ans[ji] && s[ji]=='o') found=found && !(ans[jl] ^ ans[jr]);
            else if(ans[ji] && s[ji]=='x') found=found && (ans[jl] ^ ans[jr]);
            else if(!ans[ji] && s[ji]=='o') found=found && (ans[jl] ^ ans[jr]);
            else if(!ans[ji] && s[ji]=='x') found=found && !(ans[jl] ^ ans[jr]);
        }
        if(found) break;
    }
    if(found){
        for(int i=0; i<n; ++i){
            cout << (ans[i] ? 'S' : 'W');
        }
        cout << endl;
    } else cout << -1 << endl;
    return 0;
}
