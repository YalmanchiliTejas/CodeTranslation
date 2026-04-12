#include<bits/stdc++.h>
#include <unordered_map>
#define int long long int
#define double long double
#define endl "\n"
#define PI 3.141592653589793238462643383279502884
#define sum_up(x)  (x*(x+1))/2
#define sp(x)   setprecision(x)
#define ceil(a,b)   (a+(b-1))/b
#define mp(a,b)   make_pair(a,b)
#define LCM(a,b)    (a*b)/__gcd(a,b)
#define all(v)  v.begin(),v.end()
#define alls(s,v)  s.begin(),s.end(),v
#define gena(arr,n,nxt)  generate(arr,arr+n, nxt)
#define genv(v,nxt)  generate(v.begin(),v.end(), nxt)
#define BSv(v,a) binary_search(v.begin(),v.end(), a)
#define BSa(v,n,a) binary_search(v,v+n, a)

using namespace std;

void base()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}

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
/*int power(int x, int y)
{
    int res = 1;
    while (y > 0)
    {
        if (y & 1)
            res = res * x;
        y = y >> 1;
        x = x*x;
    }
    return res;
}*/

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
}

int nxt()
{
    int x;
    cin >> x;
    return x;
}

bool ispalindrome(string str)
{
    vector<char> List;
    for (int i = 0; i < str.length(); i++)
    {
        auto pos = find(List.begin(), List.end(), str[i]);
        if (pos != List.end())
        {
            auto posi = find(List.begin(), List.end(),str[i]);
            List.erase(posi);
        }
        else
            List.push_back(str[i]);
    }
    if (str.length() % 2 == 0 && List.empty()|| (str.length() % 2 == 1 && List.size() == 1))
        return true;
    else
        return false;

}
void printArray(vector<int> arr, int n,vector<string>v)
{
    string s;
    for(int i=0; i<arr.size(); i++)
        s+=v[arr[i]];
}
void printSubsequences(vector<int> arr, int index,
                       vector<int> subarr,vector<string>v)
{
    if (index == arr.size())
    {
        int l = subarr.size();
        if (l != 0)
            printArray(subarr, l,v);
    }
    else
    {
        printSubsequences(arr, index + 1, subarr,v);
        subarr.push_back(arr[index]);
        printSubsequences(arr, index + 1, subarr,v);
    }
    return;
}

bool palindrome(string s)
{
    string test=s;
    reverse(all(test));
    return s== test;
}

int fast_power(int x, int y, int m)
{
    if (y == 0)
        return 1;
    int temp = fast_power(x, y / 2, m);
    temp = (temp*temp) % m;
    if (y % 2 != 0)
        temp = (temp*x) % m;
    return temp;

}

int inv(int x, int m)
{
    return fast_power(x, m - 2, m);
}

int32_t main()
{
    base();
    string s;
    cin>>s;
    cout<<(count(all(s),'A')==3||count(all(s),'A')==0?"No":"Yes");
    return 0;
}
