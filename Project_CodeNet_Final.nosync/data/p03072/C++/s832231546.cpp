#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
    int n;
    int ans = 1;
    cin >> n;
    int h[n];
    for(int i = 0; i < n; i++){
        cin >> h[i];
    }

    for(int i = 1; i < n; i++){
        int count = 0;
        for(int j = 0; j < i; j++){
            if(h[j] <= h[i]) count++;
        }
        if(count == i) ans++;
    }
    
    cout << ans << endl;

    return 0;
}
