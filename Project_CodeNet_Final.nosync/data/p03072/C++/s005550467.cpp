#include<iostream>
#include<vector>
#include<string>
#include<cmath>
#include<algorithm>

using namespace std;
typedef long long ll;

int main(){
    int n;
    cin >> n;
    vector<int> h(n);
    for (int i = 0; i < n; i++)
    {
        cin >> h[i];
    }
    int ans=1, _max=h[0];
    for (int i = 1; i < n; i++)
    {
        if(_max<=h[i]){
            ans++;
            _max = h[i];
        }
    }
    cout << ans << endl;
}