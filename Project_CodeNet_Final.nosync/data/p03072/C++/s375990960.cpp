#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;
#define rep(i,n) for(int i=0;i<(int)(n);i++)
typedef long long ll;

int main(){
    int n,ans=0;;
    cin >> n;
    vector<int> h(n);
    rep(i,n) cin >> h[i];
    rep(i,n) {
        bool a=true;
        for(int j=0;j<i;j++){
            if(h[j]>h[i]){
                a=false;
                break;
            }
        }
        if(a)ans++;
    }
    cout << ans << endl;
}
