#include <bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp>
//using namespace __gnu_pbds;
using namespace std;
typedef long long ll;
typedef long double ld;
//typedef tree<int,null_type,less<int >,rb_tree_tag,tree_order_statistics_node_update>indexed_set;
template<class T1, class T2>
ostream &operator <<(ostream &os, pair<T1,T2>&p);
template <class T>
ostream &operator <<(ostream &os, vector<T>&v);
template <class T>
ostream &operator <<(ostream &os, set<T>&v);
template <class T1, class T2>
ostream &operator <<(ostream &os, map<T1,T2>&v);
#ifdef APURBA
#define HERE cout<<"here - "<<__LINE__<<"\n";
#define debug(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); }
void err(istream_iterator<string> it)
{
    cout<<endl;
}
template<typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args)
{
    cout << *it << " = " << a << " ";
    err(++it, args...);
}
#else
#define HERE
#define debug(args...)
#endif
const ll mod = 1e9+7 ;
const int N = (1<<17);
typedef pair<int,int> pii;
int add(int a, int b)
{
    a+=b;
    if(a>=mod)
        a-=mod;
    return a;
}
int sub(int a, int b)
{
    a-=b;
    if(a<0)
        a+= mod;
    return a;
}
int mul(int a, int b)
{
    return a*1ll*b %mod;
}
void TEST_CASES(int cas)
{
    int n;
    scanf("%d",&n);
    int sum =0;
    vector<int>a(n);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
        sum = add(sum , a[i]);
    }
    int ans =0;
    for(int i=0;i<n;i++)
    {
        int now = a[i];
        sum = sub(sum , a[i]);
        ans = add(ans , mul(now,sum));
    }
    printf("%d\n",ans);
}


/*

*/

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    int t=1,cas=0;
    //scanf("%d",&t);
    while(t--)
    {
        TEST_CASES(++cas);
    }
    return 0;
}



template<class T1, class T2>
ostream &operator <<(ostream &os, pair<T1,T2>&p)
{
    os<<"{"<<p.first<<", "<<p.second<<"} ";
    return os;
}
template <class T>
ostream &operator <<(ostream &os, vector<T>&v)
{
    os<<"[ ";
    for(int i=0; i<v.size(); i++)
    {
        os<<v[i]<<" " ;
    }
    os<<" ]";
    return os;
}

template <class T>
ostream &operator <<(ostream &os, set<T>&v)
{
    os<<"[ ";
    for(T i:v)
    {
        os<<i<<" ";
    }
    os<<" ]";
    return os;
}
template <class T1, class T2>
ostream &operator <<(ostream &os, map<T1,T2>&v)
{
    for(auto i:v)
    {
        os<<"Key : "<<i.first<<" , Value : "<<i.second<<endl;
    }
    return os;
}

