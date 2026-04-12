#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int h[100];
    int high = 0;
    int ans = 0;
    for(int i = 0; i < n; i++){
        cin >> h[i];
        if(h[i] >= high){
            high = h[i];
            ans++;
        }
    }
    cout << ans << endl;
}