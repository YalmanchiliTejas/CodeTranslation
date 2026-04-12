#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define fi first
#define se second
int main(){
    int n,ans=1,max;
    cin >> n;
    vector<int> v(n);
    for(int i=0;i < n;i++)
    {
        cin >> v.at(i);
    }
    
    max = v.at(0);
    for(int i=1;i < n;i++)
    {
        if(v.at(i)>=max){
            ans++;
            max=v.at(i);
        }
    }
    cout << ans << endl;
}

