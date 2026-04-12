#include <bits/stdc++.h>
using namespace std;

int main(){
    //入力
    int n;
    cin >> n;
    vector<int>yama(n);
    for(int i=0;i<n;i++)
    {
        cin >> yama[i];
    }

    //処理
    int ans=1;
    int max_=yama[0];
    for(int i=1;i<n;i++)
    {
        if(max_<=yama[i])
        {
            ans++;
            max_=yama[i];
        }
    }

    //出力
    cout << ans << endl;
}