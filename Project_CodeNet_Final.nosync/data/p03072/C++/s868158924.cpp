#include<iostream>
#include<algorithm>
using namespace std;

int main(){
    int n;
    cin >> n;
    int ans = 0;
    int maxv = 0;
    for (int i = 0; i < n; i++)
    {
        int in;
        cin >> in;
        if(maxv<=in)
        {
            ans++;
            maxv = in;
        }
    }
    cout << ans << endl;
    return 0;
}