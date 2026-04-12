#include<bits/stdc++.h>
#include <unordered_map>
#define int long long int
#define double long double
#define endl "\n"
#define PI 3.141592653589793238462643383279502884
#define sum_up(x)  (x*(x+1))/2
#define sp(x)   setprecision(x)
#define ceil(a,b)   (a+(b-1))/b

using namespace std;

void base()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}
/*
bool prime[100001];
void sieve(int n)
{
    memset(prime, true, sizeof(prime));

    for (int p=2; p*p<=n; p++)
    {
        if (prime[p] == true)
        {
            for (int i=p*p; i<=n; i += p)
                prime[i] = false;
        }
    }
}
int power(int x, int y)
{
    int res = 1;
    while (y > 0)
    {
        if (y & 1)
            res = res * x;
        y = y >> 1;
        x = x * x;
    }
    return res;
}

double float_sq(double n)
{
    double x = n;
    double y = 1;
    double e = 0.000001;
    while (x - y > e)
    {
        x = (x + y) / 2;
        y = n / x;
    }
    return x;
}

int int_sq(int x)
{
    if (x == 0 || x == 1)
        return x;
    int start = 1, end = x, ans;
    while (start <= end)
    {
        int mid = (start + end) / 2;
        if (mid*mid == x)
            return mid;
        if (mid*mid < x)
        {
            start = mid + 1;
            ans = mid;
        }
        else
            end = mid-1;
    }
    return ans;
}*/

int32_t main()
{
    base();
    int n;
    cin>>n;
    vector<int>v(n);
    for(int i=0;i<n;i++)cin>>v[i];
    multiset<int>st;
    for(int i=0;i< n;i++) {
        auto itr = st.lower_bound(v[i]);
        if (st.size() == 0) st.insert(v[i]);
        if (itr == st.begin()) st.insert(v[i]);
        else{
        itr--;
        st.erase(itr);
        st.insert(v[i]);
        }
    }
    cout<<st.size();
    return 0;
}
