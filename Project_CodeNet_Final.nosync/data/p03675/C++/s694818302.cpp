#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    int n;
    cin >> n;

    vector<int> a(300000);
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    int cnt;
    cnt=n-1;
    while(cnt>=0){
        if(cnt==n-1) cout << a[cnt];
        else cout << ' ' << a[cnt];
        cnt-=2;
    }
    if(n%2==0) cnt=0;
    else cnt=1;
    while(cnt<n){
        cout << ' ' << a[cnt];
        cnt+=2;
    }
    
    return 0;
}