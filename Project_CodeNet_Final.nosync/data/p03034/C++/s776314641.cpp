#include<iostream>
using namespace std;
int main(){
    int n;
    cin >> n;
    int s[n];
    for(int i=0;i<n;i++) cin >> s[i];

    long ans = 0;
    for(int c=1;c<n-1;c++){
        long dp=0;
        for(int k=1;k*c<n-1;k++){
            if((n-1)%c==0 && 2*k*c>=n-1) break;
            if((n-1)%c!=0 && (k+1)*c>=n-1) break;
            dp+=s[n-1-k*c]+s[k*c];
            ans = max(ans, dp);
        }
    }
    cout << ans << endl;
    return 0;
}
