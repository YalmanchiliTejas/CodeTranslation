#include <bits/stdc++.h>
#define ll long long
#define INF 1000000000
using namespace std;
int main(){
    int N;
    int s;
    int smax,smin;
    int sum;
    while(1){
        cin >> N;
        if(N==0) return 0;
        smax = 0; smin = INF; sum = 0;
        for(int i=0;i<N;i++){
            cin >> s;
            smax = max(smax,s);
            smin = min(smin,s);
            sum += s;
        }
        sum = sum - smax - smin;
        int ans = sum/(N-2);
        cout << ans << endl;
    }
}
