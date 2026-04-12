#include <bits/stdc++.h>
using namespace std;
int main()
{
    long long n;
    int x, m;
    vector<int>check(200001,0);
    vector<long long>store(200001,0);

    cin >> n >> x >> m;
    check[x] = 1;
    store[1] = x;
    long long next = x;
    long long ans = x;
    for(long long i=2; i<=n; i++){
        next = (next * next) % m;
        if(check[next]){
            long long sum = 0;
            for(long long j=check[next]; j<i; j++){
                sum += store[j];
            }
            long long length = i - check[next];
            long long togo = n - i + 1;
            ans += (togo/length)*sum;
            for(long long j=check[next]; j<check[next]+togo%length; j++){
                ans += store[j];
            }
            break;
        }
        else{
            ans += next;
            check[next] = i;
            store[i] = next;
        }
    }
    cout << ans << '\n';
    return 0;
}
