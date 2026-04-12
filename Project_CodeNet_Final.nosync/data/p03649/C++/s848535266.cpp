#include <bits/stdc++.h>
#define int long long

using namespace std;


int const N = 55;
int a[N];

int Max(int n){
    int M = 0;
    for(int i=1; i<=n; i++)
        M = max(M, a[i]);
    return M;
}

int Get(int n, int mid){
    memset(a, 0, sizeof(a));
    a[1] = mid;
    int cnt = 0;
    int M = 0;
    while( (M = Max(n)) >= n){
        int num = 0;
        for(int i=1; i<=n; i++){
            if(a[i] == M){
                num++;
            }
        }
        for(int i=1; i<=n; i++)
            if(a[i] != M){
                a[i] += M / n * num;
            }
            else{
                a[i] = a[i] % n;
                a[i] += M / n * (num - 1);
            }
        cnt += M / n * (num);
    }
    return cnt;
}

void Print(int n, int val){
    cout << n << endl;
    int x = val / n;
    for(int i=1; i<n; i++)
        cout << x / n * n << "  ";
    cout << ((x / n) + x % n) * n + val % n;
}

bool Check(int n, int k){
    int L = -1;
    int R = k + 50 * 50;
    while(R - L > 1){
        int mid = (L + R) / 2;
        if(Get(n, mid) >= k)    R = mid;
        else
            L = mid;
    }
    Get(n, R-1);
    if(Get(n, R) == k){
        Print(n, R);
        return true;
    }
    return false;
}

main()
{
  //  freopen("inp.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
//    int k;
//    cin >> k;
//    for(int i=50; i>=1; i--){
//        if(Check(i, k)){
//            return 0;
//        };
//    }
    int n, M;
    cin >> n;
    for(int i=1; i<=n; i++){
        cin >> a[i];
    }

    int cnt = 0;

    while( (M = Max(n)) >= n){
        int num = 0;
        for(int i=1; i<=n; i++){
            if(a[i] == M){
                num++;
            }
        }
        for(int i=1; i<=n; i++)
            if(a[i] != M){
                a[i] += M / n * num;
            }
            else{
                a[i] = a[i] % n;
                a[i] += M / n * (num - 1);
            }
        cnt += M / n * (num);
    }
    cout << cnt;
}
