#include <iostream>
using namespace std;
typedef long long ll;

int main()
{
    int n;
    cin >> n;
    ll s[100003];
    for(int i = 0; i < n; i++) cin >> s[i];
    ll ans = 0;
    for(int i = 1; i < n; i++){
        ll sum = 0;
        for(int j = 1; ; j++){
            if((i * j >= (n - 1) - i * j && (i * j - ((n - 1) - i * j)) % i == 0) || (n - 1) - i * j < i) break;
            sum += s[i * j] + s[(n - 1) - i * j];
            ans = max(ans, sum);
        }
    }
    cout << ans << endl;
}