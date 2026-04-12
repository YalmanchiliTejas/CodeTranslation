#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;
int num[105];

int main()
{
    int n,x,mx=0,ans=0;
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> x;
        if(x>=mx){
            mx=x;
            ans++;
        }
    }
    cout << ans << endl;
}
