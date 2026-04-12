#include <bits/stdc++.h>
#define itn int
#define rep(i, n) for (int i = 0; i < n; i++)

using namespace std;
typedef long long ll;

int main() {
    int N;
    cin >> N;
    int a,tmp;
    int ans=1;
    cin >> a;
    for(int i;i!=N-1;i++){
        cin >> tmp;
        if(a>tmp){
            continue;
        }
        else{
            ans++;
            a=tmp;
        }
    }
    cout << ans << endl;
}
