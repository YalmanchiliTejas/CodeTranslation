#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //cout << "Hello world"<<"\n";
    const int m = 1000000007;
    int n;
    long long int x;
    cin >> n;
    vector<long long int> inp;
    vector<long long int> sumv;
    long long int sum = 0;
    for(int i = 0;i<n;i++)
    {
        cin >> x;
        inp.push_back(x);
        sum = (sum%m+x%m)%m;
        sumv.push_back(sum);
    }

    long long int ans = 0;
    for(int i = 1;i<n;i++)
    {
        ans = (ans%m + (inp[i]%m*sumv[i-1]%m)%m)%m;
    }
    cout << ans << endl;


    /*
    for(auto i : sumv)
        cout << i <<endl;
    */
}
