#include <cstdio>
#include <iostream>
#include <cassert>
using namespace std;

int n[6];

int main() {
    while(cin>>n[0]>>n[1]>>n[2]>>n[3]>>n[4]>>n[5]) {
        if(n[0] == 0 && n[1] == 0 && n[2] == 0
           && n[3] == 0 && n[4] == 0 && n[5] == 0) break;

        for(int i=0; i<6; ++i) {
            if(n[i] < 0) assert(false);
        }

        int ans = 0,mp = 1<<29;
        n[0] += n[3];
        n[1] += n[4];
        n[2] += n[5];

        for(int i=0; i<3; ++i)
            mp = min(n[i], mp);
        ans += mp;
        for(int i=0; i<3; ++i) ans += (n[i]-mp)/3;

        for(int k=0; k<=2; ++k) {
            if(k > mp) break;
            int tmp = k;
            for(int i=0; i<3; ++i)
                tmp += (n[i]-k)/3;
            ans = max(tmp, ans);
        }

        cout<<ans<<endl;
        
    }
}