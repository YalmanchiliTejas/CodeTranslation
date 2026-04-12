#include<bits/stdc++.h>
using namespace std;


#define  SZ(items) (int)items.size()
#define  CLR(a)  memset(a,0,sizeof(a))
#define  SET(a)  memset(a,-1,sizeof(a))
#define  nl "\n";

int dx[] = { 0,0,1,-1,-1,-1,1,1 };
int dy[] = { 1,-1,0,0,-1,1,1,-1 };



template <class T> inline T biton(T n, T pos)
{
    return n | ((T)1 << pos);
}
template <class T> inline T bitoff(T n, T pos)
{
    return n & ~((T)1 << pos);
}
template <class T> inline T ison(T n, T pos)
{
    return (bool)(n & ((T)1 << pos));
}
template <class T> inline T gcd(T a, T b)
{
    while (b)
    {
        a = a % b;
        swap(a, b);
    }
    return a;
}
template <class T> inline T bigmod(T p, T e, T m)
{
    T ret = 1;
    for (; e > 0; e >>= 1)
    {
        if (e & 1)
            ret = (ret * p) % m;
        p = (p * p) % m;
    }
    return (T)ret;
};

#ifdef DEBUG
#define debug(...) __f(#__VA_ARGS__, __VA_ARGS__)
template < typename Arg1 >
void __f(const char* name, Arg1&& arg1)
{
    cerr << name << " is " << arg1 << std::endl;
}
template < typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args)
{
    const char* comma = strchr(names + 1, ',');
    cerr.write(names, comma - names) << " is " << arg1 << " | ";
    __f(comma + 1, args...);
}
#else
#define debug(...)
#endif

int k;
string str;
vector<int> bits;

long long dp[105][2][105];

long long Recur(int pos,int isSmall,long long cnt)
{

    if ((int)bits.size() == pos)
    {
        return cnt==k;
    }

    if (dp[pos][isSmall][cnt]!= -1)
    {
        return dp[pos][isSmall][cnt];
    }

    long long sum = 0;
    int to = isSmall ? 9 : bits[pos];

    for (int i = 0; i <= to; i++)
    {
        if(cnt==k && i==0)
        {
            sum += Recur( pos + 1, isSmall || i < bits[pos], (i!=0) ? cnt + 1 : cnt);
        }
        else if(cnt<k)
        {
            sum += Recur( pos + 1, isSmall || i < bits[pos], (i!=0) ? cnt + 1 : cnt);
        }

    }

    return dp[pos][isSmall][cnt]= sum;
}

void solve()
{

    SET(dp);
    cin>>str>>k;

    for(auto t:str)
    {
        bits.push_back(t-'0');
    }


    long long a=Recur(0ll,0ll,0ll);
    cout<<a<<endl;

}

int main()
{
    ios_base::sync_with_stdio(false);
    cout.setf(ios::fixed);
    cout.precision(10);
    cout.tie(nullptr);
    cin.tie(nullptr);

    int t = 1;

    while (t--)
    {
        solve();
    }

    return 0;
}
