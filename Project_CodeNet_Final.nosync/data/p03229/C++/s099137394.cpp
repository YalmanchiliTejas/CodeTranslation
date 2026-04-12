#include <bits/stdc++.h>
 
#define Set(a, b) memset(a, (b), sizeof(a))
#define F first
#define S second
#define FT front()
#define BK back()
#define PB push_back
#define MP make_pair
#define repi(i, l, r) for (int i=l ; i <= (int)(r) ; ++i)
#define repd(i, r, l) for (int i=r ; i >= (int)(l) ; --i)
#define repv(x, v) for (auto (x) : v)
#define all(cont) cont.begin(), cont.end()
#define Sort(n) sort(all(n))
#define Sortcmp(n) sort(all(n), cmp)
#define INF (int)1e9
#define EPS 1e-9
#define PI 3.1415926535897932384626433832795
#define MOD 1000000007
#define ll long long
#define ull unsigned long long
#define nl "\n"

using namespace std;

bool cmp(const pair<long,long> &a,
              const pair<long,long> &b)
{
    return (a.second < b.second || (a.second == b.second && a.first < b.first));
}

bool binarySearch(int arr[], int n, int x){
    int k = 0;
    for (int b = n/2; b >= 1; b/2)
        while (k+b < n && arr[k+b] <= x) k += b;

    if (arr[k] == x) return k;
    return -1;
}

/* ASCII Table */
/* 48 == '0', 57 = '9', 65 == 'A', 90 == 'Z', 97 == 'a', 122 == 'z' */  

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    long n, a;

    vector<long> v;
    cin >> n;

    repi(i, 0, n-1){
        cin >> a;
        v.PB(a);
    }

    Sort(v);
    long sum1 = 0, sum2 = 0, mid1, mid2;

    mid1 = mid2 = n/2;
    if(n%2 == 0)
        mid1--;


    long left = 0;
    long right = n-1;
    repi(i, 0, n-2){
        if(i == 0)
            sum1 += (v[right]-v[mid1]);
        else{
            sum1 += (v[right]-v[left]);
            if(i%2)
                right--;
            else
                left++;
        }
    }

    left = 0;
    right = n-1;
    repi(i, 0, n-2){
        if(i == 0)
            sum2 += (v[mid2]-v[left]);
        else{
            sum2 += (v[right]-v[left]);
            if(i%2)
                left++;
            else
                right--;
        }
    }    

    cout << max(sum1, sum2) << nl;
    return 0;
}

/* Compile */
// g++ -std=c++11 -O2 -Wall test.cpp -o test
 
 
/* Source code dengan case
 
int main(){
    int T;
    cin >> T;
    for(int counterT = 1 ; counterT <= T ; T++){
         
        printf("%d\n", ans);
    }
    return 0;
}
 */
 
/* Source code dengan case
 
int main(){
    int T;
    cin >> T;
    for(int counterT = 1 ; counterT <= T ; T++){
         
        printf("Case #%d: %d\n", counterT, ans);
    }
    return 0;
}
 */