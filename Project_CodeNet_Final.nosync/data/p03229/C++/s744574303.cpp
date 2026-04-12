#include <algorithm>
#include <iostream>
using namespace std;
typedef long long ll;

int main()
{
    int n;
    cin >> n;
    ll a[100002];
    for(int i = 0; i < n; i++) cin >> a[i];
    sort(a, a + n);
    ll s1 = 0, s2 = 0;
    for(int i = 0; i < n / 2; i++) s1 += a[i];
    for(int i = 0; i < n / 2; i++) s2 += a[n - 1 - i];
    if(n % 2 == 0){
        cout << s2 - s1 + (s2 - a[n / 2]) - (s1 - a[n / 2 - 1]) << endl;
    }
    else{
        cout << s2 - s1 + max(s2 - (s1 - a[n / 2 - 1] + a[n / 2]), (s2 - a[n / 2 + 1] + a[n / 2]) - s1) << endl;
    }
}