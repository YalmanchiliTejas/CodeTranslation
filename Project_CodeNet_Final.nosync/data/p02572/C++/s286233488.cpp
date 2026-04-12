// A.cpp : このファイルには 'main' 関数が含まれています。プログラム実行の開始と終了がそこで行われます。
//

#include <iostream>
#include<string>
#include<vector>

using namespace std;



int main()
{
    int n;
    const long long waru = 1000000007;
    cin >> n;

    vector<long long> a(n);
    long long ans=0;
    long long sum = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        sum += a[i];
    }

    for (int i = 0; i < n; i++) {
        //for (int j = i+1; j < n; j++) {
        //    ans += (a[i] * a[j]) % waru;

        //    ans = ans % waru;
        //}
        sum -= a[i];
        ans += (a[i] * (sum % waru)) % waru;
        ans %= waru;
    }

    cout << ans << endl;

    return 0;
}

